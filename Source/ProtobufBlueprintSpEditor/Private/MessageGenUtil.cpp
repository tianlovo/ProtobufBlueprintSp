// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageGenUtil.h"

TMap<FString, int32> UMessageGenUtil::ReadMessageIdentifies(const FString& IdentifiesPath)
{
	TMap<FString, int32> ResultMap;

	// 读取IdentifiesPath文件内容
	if (FString FileContent;
		FFileHelper::LoadFileToString(FileContent, *IdentifiesPath))
	{
		// 定义正则表达式匹配模式
		const FRegexPattern Pattern(TEXT("static\\s+constexpr\\s+int32\\s+(\\w+)\\s*=\\s*(\\d+)"));

		// 创建正则表达式对象
		FRegexMatcher Matcher(Pattern, FileContent);

		// 迭代匹配结果
		while (Matcher.FindNext())
		{
			// 获取匹配到的变量名称和变量值
			FString VariableName = Matcher.GetCaptureGroup(1);
			FString VariableValueStr = Matcher.GetCaptureGroup(2);

			// 将变量值转为int32
			int32 VariableValue = FCString::Atoi(*VariableValueStr);

			// 存储到结果Map中
			ResultMap.Add(VariableName, VariableValue);
		}
	}

	return ResultMap;
}

void UMessageGenUtil::WriteMessageIdentifies(const TMap<FString, int32>& MessageIdentifies,
	const FString& IdentifiesPath)
{
	if (MessageIdentifies.Num() <= 0) return;
	if (!IdentifiesPath.EndsWith("FMessageIdentifies.h")) return;
	
	FString FileContent;

	// 将额外的结构内容加入字符串
	FileContent += FString::Printf(TEXT("#pragma once\n\n"));
	FileContent += FString::Printf(TEXT("class FMessageIdentifies\n"));
	FileContent += FString::Printf(TEXT("{\n"));
	FileContent += FString::Printf(TEXT("public:\n"));

	// 将TMap<FString, int32>的内容格式化为字符串
	for (const auto& Entry : MessageIdentifies)
	{
		FileContent += FString::Printf(TEXT("\tstatic constexpr int32 %s = %d;\n"), *Entry.Key, Entry.Value);
	}

	FileContent += FString::Printf(TEXT("};\n"));

	// 清空文件内容并将字符串内容写入文件
	FFileHelper::SaveStringToFile(FileContent, *IdentifiesPath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
}

void UMessageGenUtil::WriteRegisteredMessages(const TArray<FString>& MessageArray,
	const FString& RegisteredMessagesPath, const FString& PbPrefixPath, const FString& MessageNamespace)
{
	if (MessageArray.Num() <= 0) return;
	if (!RegisteredMessagesPath.EndsWith("FRegisteredMessages.h")) return;
	
	FString FileContent;

	// 将额外的结构内容加入字符串
	FileContent += FString::Printf(TEXT("#pragma once\n\n"));
	FileContent += FString::Printf(TEXT("#include \"FMessageIdentifies.h\"\n"));
	FileContent += FString::Printf(TEXT("#include \"google/protobuf/message.h\"\n"));
	FileContent += FString::Printf(TEXT("\n"));

	// .pb.h头文件引用
	if (PbPrefixPath.IsEmpty())
	{
		for (const FString& Message : MessageArray)
		{
			FileContent += FString::Printf(TEXT("#include \"%s.pb.h\"\n"), *Message);
		}
	}
	else
	{
		for (const FString& Message : MessageArray)
		{
			FileContent += FString::Printf(TEXT("#include \"%s/%s.pb.h\"\n"), *PbPrefixPath, *Message);
		}
	}
	
	// 生成RegisteredMessages的内容
	FileContent += FString::Printf(TEXT("\nclass FRegisteredMessages\n"));
	FileContent += FString::Printf(TEXT("{\n"));
	FileContent += FString::Printf(TEXT("public:\n"));
	FileContent += FString::Printf(TEXT("\tinline static const TMap<int32, TSharedPtr<google::protobuf::Message>> RegisteredMessages{\n"));

	// 写入Map值
	if (MessageNamespace.IsEmpty())
	{
		for (const FString& Message : MessageArray)
		{
			FileContent += FString::Printf(TEXT("\t\t{FMessageIdentifies::%s, MakeShared<%s>()},\n"), *Message, *Message);
		}
	}
	else
	{
		for (const FString& Message : MessageArray)
		{
			FileContent += FString::Printf(
				TEXT("\t\t{FMessageIdentifies::%s, MakeShared<%s::%s>()},\n"), *Message, *MessageNamespace, *Message);
		}
	}
	
	FileContent += FString::Printf(TEXT("\t};\n"));
	FileContent += FString::Printf(TEXT("};\n"));

	// 清空文件内容并将字符串内容写入文件
	FFileHelper::SaveStringToFile(FileContent, *RegisteredMessagesPath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
}
