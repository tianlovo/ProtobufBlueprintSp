// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtobufMessage.h"

#include "Constant/FRegisteredMessages.h"
#include "Util/PropertyUtil.h"
#include "Util/ProtobufUtil.h"

TMap<int32, TSubclassOf<UProtobufMessage>> UProtobufMessage::IdentifyMap = TMap<int32, TSubclassOf<UProtobufMessage>>();

void UProtobufMessage::PostInitProperties()
{
	UObject::PostInitProperties();

	if (IdentifyMap.IsEmpty())
	{
		InitIdentifyMap();
	}
}

void UProtobufMessage::InitIdentifyMap()
{
	// 遍历所有类
	TArray<UClass*> DerivedClasses;
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (UClass* CurrentClass = *It;
			CurrentClass->IsChildOf(StaticClass()))
		{
			// xxx_C才是目标蓝图类，例如：TestProtobufMessage_C
			if (FString ClassName = *CurrentClass->GetName();
				ClassName.EndsWith("_C"))
			{
				// 获取蓝图消息子类标识符
				const UProtobufMessage* Message = Cast<UProtobufMessage>(CurrentClass->GetDefaultObject());
				if (!Message) continue;

				// 添加映射
				if (!FRegisteredMessages::RegisteredMessages.Contains(Message->Identify)) continue;
				IdentifyMap.Add(Message->Identify, CurrentClass);
			}
		}
	}
}

UProtobufMessage* UProtobufMessage::CreateMessage(const TSubclassOf<UProtobufMessage> MessageClass)
{
	if (MessageClass)
	{
		return NewObject<UProtobufMessage>(GetTransientPackage(), MessageClass.Get());
	}
	
	return nullptr;
}

TArray<uint8> UProtobufMessage::ToProtobufBytes(const UProtobufMessage* Message)
{
	// 字典没有此CmdId直接返回空字节数组
	TArray<uint8> ProtobufBytes;
	const auto FoundMessage = FRegisteredMessages::RegisteredMessages[Message->Identify].Get();
	if (!FoundMessage) return ProtobufBytes;

	// 新建消息对象用以后续赋值
	google::protobuf::Message* BuildMessage = MessageFactory::generated_factory()->
	GetPrototype(FRegisteredMessages::RegisteredMessages[Message->Identify].Get()->
		GetDescriptor())->New();

	// 获取UE的消息对象的值来设置Protobuf对象的设置的值
	const UClass* MsgClass = Message->GetClass();
	for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
	{
		const FProperty* Property = *PropertyIt;
		// 分类检查
		if (!FPropertyUtil::IsPropertyInCategory(Property, TEXT("Protobuf|Property"))) continue;
		
		FProtobufUtil::SetProtobufByUE(Message, Property, FoundMessage, BuildMessage);
	}

	// 将消息对象序列化为字节数组
	const int32 Size = BuildMessage->ByteSizeLong();
	ProtobufBytes.SetNumUninitialized(Size);
	io::ArrayOutputStream ArrayOutputStream(ProtobufBytes.GetData(), Size);
	io::CodedOutputStream CodedOutputStream(&ArrayOutputStream);
	BuildMessage->SerializeToCodedStream(&CodedOutputStream);

	return ProtobufBytes;
}

bool UProtobufMessage::FromProtobufBytes(const int32 MessageIdentify, TArray<uint8> ProtobufData, UProtobufMessage* Message)
{
	// 字典没有此CmdId直接返回
	const auto FoundMessage = FRegisteredMessages::RegisteredMessages[MessageIdentify].Get();
	if (!FoundMessage) return false;

	if (FoundMessage->ParseFromArray(ProtobufData.GetData(), ProtobufData.Num()))
	{
		Message->Identify = MessageIdentify;

		// 获取Protobuf对象的设置的值来设置UE的消息对象的值
		const UClass* MsgClass = Message->GetClass();
		for (TFieldIterator<FProperty> PropertyIt(MsgClass); PropertyIt; ++PropertyIt)
		{
			const FProperty* Property = *PropertyIt;
			// 分类检查
			if (!FPropertyUtil::IsPropertyInCategory(Property, TEXT("Protobuf|Property"))) continue;
			
			FProtobufUtil::SetUEByProtobuf(Message, Property, FoundMessage);
		}
		return true;
	}

	return false;
}

bool UProtobufMessage::CreateMessageByProtobuf(const int32 MessageIdentify, const TArray<uint8> ProtobufData,
	UProtobufMessage*& Message)
{
	if (IdentifyMap.IsEmpty())
	{
		InitIdentifyMap();
	}
	// 输入的标识符为注册(不存在)
	if (!IdentifyMap.Contains(MessageIdentify)) return false;

	// 通过Identify查找对应的蓝图消息类
	Message = CreateMessage(IdentifyMap[MessageIdentify]);
	FromProtobufBytes(MessageIdentify, ProtobufData, Message);

	// 浅校验
	return Message->Identify == MessageIdentify;
}
