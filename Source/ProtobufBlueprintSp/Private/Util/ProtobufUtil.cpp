// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/ProtobufUtil.h"

#include "Constant/FRegisteredMessages.h"
#include "Util/PropertyUtil.h"

FString FProtobufUtil::ToSnakeCase(const FString& InputString)
{
	// 遍历字符串，将大写字母转为小写并在前面加下划线
	FString Result;
	for (const TCHAR& Char : InputString)
	{
		if (FChar::IsUpper(Char))
		{
			Result += TEXT('_');
			Result += FChar::ToLower(Char);
		}
		else
		{
			Result += Char;
		}
	}

	// 去除可能开头的下划线
	if (Result.StartsWith(TEXT("_")))
	{
		Result.RemoveAt(0);
	}

	return Result;
}

void FProtobufUtil::SetProtobufByUE(const UProtobufMessage* Object, const FProperty* ObjectProperty,
	Message* FoundMessage, Message* BuildMessage)
{
	const Reflection* Reflection = FoundMessage->GetReflection();
	const Descriptor* Descriptor = FoundMessage->GetDescriptor();

	// 判断Protobuf是否有UE属性名称
	if (const FieldDescriptor* FindField =
		Descriptor->FindFieldByName(TCHAR_TO_UTF8(*ToSnakeCase(ObjectProperty->GetName()))))
	{
		///---------- ue -> proto ----------

		///------------------------------------ Single ------------------------------------
		// int32 -> int32/sint32/sfixed32
		if (const auto IntProperty = CastField<FIntProperty>(ObjectProperty))
		{
			Reflection->SetInt32(BuildMessage, FindField, *IntProperty->ContainerPtrToValuePtr<int32>(Object));
		}
		// int64 -> int64/sint64/sfixed64
		else if (const auto Int64Property = CastField<FInt64Property>(ObjectProperty))
		{
			Reflection->SetInt64(BuildMessage, FindField, *Int64Property->ContainerPtrToValuePtr<int64>(Object));
		}
		// uint32 -> uint32/fixed32
		else if (const auto UInt32Property = CastField<FUInt32Property>(ObjectProperty))
		{
			Reflection->SetUInt32(BuildMessage, FindField, *UInt32Property->ContainerPtrToValuePtr<uint32>(Object));
		}
		// uint64 -> uint64/fixed64
		else if (const auto UInt64Property = CastField<FUInt64Property>(ObjectProperty))
		{
			Reflection->SetUInt64(BuildMessage, FindField, *UInt64Property->ContainerPtrToValuePtr<uint64>(Object));
		}
		// double -> double
		else if (const auto DoubleProperty = CastField<FDoubleProperty>(ObjectProperty))
		{
			Reflection->SetDouble(BuildMessage, FindField, *DoubleProperty->ContainerPtrToValuePtr<double>(Object));
		}
		// float -> float
		else if (const auto FloatProperty = CastField<FFloatProperty>(ObjectProperty))
		{
			Reflection->SetFloat(BuildMessage, FindField, *FloatProperty->ContainerPtrToValuePtr<float>(Object));
		}
		// bool -> bool
		else if (const auto BoolProperty = CastField<FBoolProperty>(ObjectProperty))
		{
			Reflection->SetBool(BuildMessage, FindField, *BoolProperty->ContainerPtrToValuePtr<bool>(Object));
		}
		// enum/byte -> enum
		else if (const auto EnumProperty = CastField<FByteProperty>(ObjectProperty))
		{
			const unsigned char Value = EnumProperty->GetPropertyValue_InContainer(Object);

			// enum
			if (ObjectProperty->GetCPPType().Contains("TEnumAsByte", ESearchCase::IgnoreCase))
			{
				Reflection->SetEnumValue(BuildMessage, FindField, Value);
			}
			// byte
			else
			{
				std::stringstream SS;
				SS << Value;
				Reflection->SetString(BuildMessage, FindField, SS.str());
			}
		}
		// string -> string/bytes
		else if (const auto StringProperty = CastField<FStrProperty>(ObjectProperty))
		{
			FString Value = *StringProperty->ContainerPtrToValuePtr<FString>(Object);
			Reflection->SetString(BuildMessage, FindField, TCHAR_TO_UTF8(*Value));
		}
		// message -> message
		else if(const auto MessageProperty = CastField<FObjectProperty>(ObjectProperty))
		{
			UObject* ObjectValue = MessageProperty->GetObjectPropertyValue_InContainer(Object);
			if (auto MessageObject = Cast<UProtobufMessage>(ObjectValue))
			{
				if (MessageObject == nullptr) return;
				
				// 获取嵌套消息的可变引用
				if (auto MutableNestedMessage = Reflection->MutableMessage(BuildMessage, FindField))
				{
					// 嵌套消息类型查找
					const auto NestedFoundMessage = FRegisteredMessages::RegisteredMessages[MessageObject->Identify].Get();
					if (!NestedFoundMessage) return;
					
					// 循环设置嵌套消息的属性
					const UClass* MsgClass = MessageObject->GetClass();
					for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
					{
						FProperty* ItProperty = *PropertyIt;
						// 分类检查
						if (!FPropertyUtil::IsPropertyInCategory(ItProperty, TEXT("Protobuf|Property"))) continue;
						SetProtobufByUE(MessageObject, ItProperty, NestedFoundMessage, MutableNestedMessage);
					}
				}
			}
		}
		
		///------------------------------------ Repeated ------------------------------------
		// array -> repeated
		else if(const auto ArrayProperty = CastField<FArrayProperty>(ObjectProperty))
		{
			// FArrayProperty遍历 参考：https://blog.csdn.net/sinat_34870723/article/details/128850755
			for (int32 DimIndex = 0; DimIndex < ArrayProperty->ArrayDim; ++DimIndex)
			{
				FScriptArrayHelper_InContainer ScriptArrayHelper(ArrayProperty, Object, DimIndex);
				const int32 ArrayNum = ScriptArrayHelper.Num();
				const auto InnerProperty = ArrayProperty->Inner;

				// int32 -> repeated int32/sint32/sfixed32
				if (const auto Int32SubProperty = CastField<FIntProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const int32 Value = *Int32SubProperty->ContainerPtrToValuePtr<int32>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddInt32(BuildMessage, FindField, Value);
					}
				}
				// int64 -> repeated int64/sint64/sfixed64
				else if (const auto Int64SubProperty = CastField<FInt64Property>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const int64 Value = *Int64SubProperty->ContainerPtrToValuePtr<int64>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddInt64(BuildMessage, FindField, Value);
					}
				}
				// uint32 -> repeated uint32/fixed32/
				else if (const auto Uint32SubProperty = CastField<FUInt32Property>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const uint32 Value = *Uint32SubProperty->ContainerPtrToValuePtr<uint32>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddUInt32(BuildMessage, FindField, Value);
					}
				}
				// uint64 -> repeated uint64/fixed64/
				else if (const auto Uint64SubProperty = CastField<FUInt64Property>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const uint64 Value = *Uint64SubProperty->ContainerPtrToValuePtr<uint64>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddUInt64(BuildMessage, FindField, Value);
					}
				}
				// double -> repeated double
				else if (const auto DoubleSubProperty = CastField<FDoubleProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const double Value = *DoubleSubProperty->ContainerPtrToValuePtr<double>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddDouble(BuildMessage, FindField, Value);
					}
				}
				// float -> repeated float
				else if (const auto FloatSubProperty = CastField<FFloatProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const float Value = *FloatSubProperty->ContainerPtrToValuePtr<float>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddFloat(BuildMessage, FindField, Value);
					}
				}
				// bool -> repeated bool
				else if (const auto BoolSubProperty = CastField<FBoolProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						const bool Value = *BoolSubProperty->ContainerPtrToValuePtr<bool>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddBool(BuildMessage, FindField, Value);
					}
				}
				// enum/byte -> repeated enum
				else if (const auto EnumSubProperty = CastField<FByteProperty>(InnerProperty))
				{
					// enum[]
					if (ObjectProperty->GetCPPType().Contains("TEnumAsByte", ESearchCase::IgnoreCase))
					{
						for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
						{
							const unsigned char Value = EnumSubProperty->GetPropertyValue_InContainer(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
							Reflection->AddEnumValue(BuildMessage, FindField, Value);
						}
					}
					// byte[]
					else
					{
						std::stringstream SS; // for build bytes
						for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
						{
							const unsigned char Value = EnumSubProperty->GetPropertyValue_InContainer(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
							SS << Value;
						}
						Reflection->SetString(BuildMessage, FindField, SS.str());
					}
				}
				// string -> repeated string
				else if (const auto StringSubProperty = CastField<FStrProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						FString Value = *StringSubProperty->ContainerPtrToValuePtr<FString>(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						Reflection->AddString(BuildMessage, FindField, TCHAR_TO_UTF8(*Value));
					}
				}
				// message -> repeated message
				else if (const auto MessageSubProperty = CastField<FObjectProperty>(InnerProperty))
				{
					for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
					{
						UObject* ObjectValue = MessageSubProperty->GetObjectPropertyValue_InContainer(
							ScriptArrayHelper.GetRawPtr(DynamicIndex));
						if (auto MessageObject = Cast<UProtobufMessage>(ObjectValue))
						{
							if (MessageObject == nullptr) return;

							// 嵌套消息类型查找
							const auto NestedFoundMessage =
								FRegisteredMessages::RegisteredMessages[MessageObject->Identify].Get();
							if (!NestedFoundMessage) return;

							// 新建消息对象用以后续赋值
							Message* NestedBuildMessage = MessageFactory::generated_factory()->
														  GetPrototype(NestedFoundMessage->GetDescriptor())->New();
							
							// 循环设置嵌套消息的属性
							const UClass* MsgClass = MessageObject->GetClass();
							for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
							{
								FProperty* ItProperty = *PropertyIt;
								// 分类检查
								if (!FPropertyUtil::IsPropertyInCategory(ItProperty, TEXT("Protobuf|Property"))) continue;
								SetProtobufByUE(MessageObject, ItProperty, NestedFoundMessage, NestedBuildMessage);
							}

							// 添加消息
							Reflection->AddAllocatedMessage(BuildMessage, FindField, NestedBuildMessage);
						}
					}
				}
			}
		}
	}
}

void FProtobufUtil::SetUEByProtobuf(UProtobufMessage* Object, const FProperty* ObjectProperty, Message* FoundMessage)
{
	const Reflection* Reflection = FoundMessage->GetReflection();
	const Descriptor* Descriptor = FoundMessage->GetDescriptor();

	// 判断Protobuf是否有UE属性名称
	if (const FieldDescriptor* FindField =
		Descriptor->FindFieldByName(TCHAR_TO_UTF8(*ToSnakeCase(ObjectProperty->GetName()))))
	{
		///---------- proto -> ue ----------

		///------------------------------------ Single ------------------------------------
		if (!FindField->is_repeated())
		{
			// int32/sint32/sfixed32 -> int32
			if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_INT32)
			{
				const auto NewValue = Reflection->GetInt32(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FIntProperty>(ObjectProperty))
				{
					// 设置属性值 参考：https://zhuanlan.zhihu.com/p/664578637
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// int64/sint64/sfixed64 -> int64
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_INT64)
			{
				const auto NewValue = Reflection->GetInt64(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FInt64Property>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// uint32/fixed32 -> uint32
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_UINT32)
			{
				const auto NewValue = Reflection->GetUInt32(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FUInt32Property>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// uint64/fixed64 -> uint64
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_UINT64)
			{
				const auto NewValue = Reflection->GetUInt64(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FUInt64Property>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// double -> double
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_DOUBLE)
			{
				const auto NewValue = Reflection->GetDouble(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FDoubleProperty>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// float -> float
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_FLOAT)
			{
				const auto NewValue = Reflection->GetFloat(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FFloatProperty>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// bool -> bool
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_BOOL)
			{
				const auto NewValue = Reflection->GetBool(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FBoolProperty>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// enum -> enum
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_ENUM)
			{
				const auto NewValue = Reflection->GetEnumValue(*FoundMessage, FindField);
				if (const auto CastProperty = CastField<FByteProperty>(ObjectProperty))
				{
					const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(Object);
					CastProperty->SetPropertyValue(ValuePtr, NewValue);
				}
			}
			// string/bytes -> FString/uint8/TArray<uint8>
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_STRING)
			{
				const auto NewValue = Reflection->GetString(*FoundMessage, FindField);

				// string/bytes -> FString
				if (const auto StringProperty = CastField<FStrProperty>(ObjectProperty))
				{
					const auto ValuePtr = StringProperty->ContainerPtrToValuePtr<FString>(Object);
					StringProperty->SetPropertyValue(ValuePtr, FString(UTF8_TO_TCHAR(NewValue.c_str())));
				}
				// string/bytes -> uint8
				else if(const auto ByteProperty = CastField<FByteProperty>(ObjectProperty))
				{
					const auto ValuePtr = ByteProperty->ContainerPtrToValuePtr<void>(Object);
					ByteProperty->SetPropertyValue(ValuePtr, static_cast<uint8>(NewValue[0]));
				}
				// string/bytes -> TArray<uint8>
				else if(const auto ArrayProperty = CastField<FArrayProperty>(ObjectProperty))
				{
					for (int32 DimIndex = 0; DimIndex < ArrayProperty->ArrayDim; ++DimIndex)
					{
						FScriptArrayHelper_InContainer ScriptArrayHelper(ArrayProperty, Object, DimIndex);
						const int32 ArrayNum = NewValue.length();
						const auto InnerProperty = ArrayProperty->Inner;

						ScriptArrayHelper.EmptyValues();
						ScriptArrayHelper.AddValues(ArrayNum);

						// uint8
						if (const auto ByteSubProperty = CastField<FByteProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = ByteSubProperty->ContainerPtrToValuePtr<uint8>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								ByteSubProperty->SetPropertyValue(ValuePtr, static_cast<uint8>(NewValue[DynamicIndex]));
							}
						}
					}
				}
			}
			// message -> message
			else if(FindField->cpp_type() == FieldDescriptor::CPPTYPE_MESSAGE)
			{
				// 获取嵌套消息的可变引用
				auto MutableNestedMessage = Reflection->MutableMessage(FoundMessage, FindField);
				if (!MutableNestedMessage) return;

				if (const auto CastProperty = CastField<FObjectProperty>(ObjectProperty))
				{
					// 创建一个新的消息对象以便后续赋值
					UClass* MsgClass = CastProperty->PropertyClass.Get();
					UProtobufMessage* NewMessage = NewObject<UProtobufMessage>(
						Object, MsgClass);

					// 循环设置嵌套消息的属性
					for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
					{
						FProperty* ItProperty = *PropertyIt;
						// 分类检查
						if (!FPropertyUtil::IsPropertyInCategory(ItProperty,
							TEXT("Protobuf|Property"))) continue;
							
						SetUEByProtobuf(NewMessage, ItProperty, MutableNestedMessage);
					}
						
					// 设置父类对象的嵌套对象
					CastProperty->SetObjectPropertyValue_InContainer(Object, NewMessage);
				}
			}
		}
		///------------------------------------ Repeated -----------------------------------
		else
		{
			// array
			if (const auto ArrayProperty = CastField<FArrayProperty>(ObjectProperty))
			{
				for (int32 DimIndex = 0; DimIndex < ArrayProperty->ArrayDim; ++DimIndex)
				{
					FScriptArrayHelper_InContainer ScriptArrayHelper(ArrayProperty, Object, DimIndex);
					const int32 ArrayNum =Reflection->FieldSize(*FoundMessage, FindField);
					const auto InnerProperty = ArrayProperty->Inner;
					
					ScriptArrayHelper.EmptyValues();
					ScriptArrayHelper.AddValues(ArrayNum);

					// repeated int32/sint32/sfixed32 -> int32[]
					if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_INT32)
					{
						if (const auto CastProperty = CastField<FIntProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedInt32(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated int64/sint64/sfixed64 -> int64[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_INT64)
					{
						if (const auto CastProperty = CastField<FInt64Property>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedInt64(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated uint32/fixed32 -> uint32[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_UINT32)
					{
						if (const auto CastProperty = CastField<FUInt32Property>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedUInt32(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated uint64/fixed64-> uint64[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_UINT64)
					{
						if (const auto CastProperty = CastField<FUInt64Property>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedUInt64(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated double-> double[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_DOUBLE)
					{
						if (const auto CastProperty = CastField<FDoubleProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedDouble(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated float-> float[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_FLOAT)
					{
						if (const auto CastProperty = CastField<FFloatProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedFloat(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated bool -> bool[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_BOOL)
					{
						if (const auto CastProperty = CastField<FBoolProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<bool>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedBool(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated enum -> enum[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_ENUM)
					{
						if (const auto CastProperty = CastField<FByteProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									Reflection->GetRepeatedEnumValue(*FoundMessage, FindField, DynamicIndex));
							}
						}
					}
					// repeated string -> string[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_STRING)
					{
						if (const auto CastProperty = CastField<FStrProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetPropertyValue(ValuePtr,
									UTF8_TO_TCHAR(Reflection->GetRepeatedString(*FoundMessage, FindField, DynamicIndex).c_str()));
							}
						}
					}
					// repeated bytes -> 不存在TArray<TArray<uint8>>
					// repeated message -> message[]
					else if (FindField->cpp_type() == FieldDescriptor::CPPTYPE_MESSAGE)
					{
						if (const auto CastProperty = CastField<FObjectProperty>(InnerProperty))
						{
							for (int32 DynamicIndex = 0; DynamicIndex < ArrayNum; ++DynamicIndex)
							{
								// 获取嵌套消息的可变引用
								auto MutableNestedMessage = Reflection->
								MutableRepeatedMessage(FoundMessage, FindField, DynamicIndex);
								if (!MutableNestedMessage) return;

								// 创建一个新的消息对象以便后续赋值
								UClass* MsgClass = CastProperty->PropertyClass.Get();
								UProtobufMessage* NewMessage = NewObject<UProtobufMessage>(
									Object, MsgClass);

								// 循环设置嵌套消息的属性
								for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
								{
									FProperty* ItProperty = *PropertyIt;
									// 分类检查
									if (!FPropertyUtil::IsPropertyInCategory(ItProperty,
										TEXT("Protobuf|Property"))) continue;
							
									SetUEByProtobuf(NewMessage, ItProperty, MutableNestedMessage);
								}
						
								// 设置数组元素的嵌套对象
								const auto ValuePtr = CastProperty->ContainerPtrToValuePtr<void>(
									ScriptArrayHelper.GetRawPtr(DynamicIndex));
								CastProperty->SetObjectPropertyValue_InContainer(ValuePtr, NewMessage);
							}
						}
					}
				}
			}
		}
	}
}
