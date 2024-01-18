// Author's Github: https://github.com/tianlovo


#include "MessageGenUtil.h"

#include "HAL/PlatformProcess.h"

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
                                             const FString& IdentifiesPath, const bool bIsCreate)
{
	if (!bIsCreate && MessageIdentifies.Num() <= 0) return;
	if (!IdentifiesPath.EndsWith("FMessageIdentifies.h")) return;

	FString FileContent;

	// 将额外的结构内容加入字符串
	FileContent += FString::Printf(TEXT("#pragma once\n\n"));
	FileContent += FString::Printf(TEXT("class PROTOBUFBLUEPRINTSP_API FMessageIdentifies\n"));
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
                                              const FString& RegisteredMessagesPath, const FString& PbPrefixPath,
                                              const FString& MessageNamespace, const bool bIsCreate)
{
	if (!bIsCreate && MessageArray.Num() <= 0) return;
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
	FileContent += FString::Printf(TEXT("\nclass PROTOBUFBLUEPRINTSP_API FRegisteredMessages\n"));
	FileContent += FString::Printf(TEXT("{\n"));
	FileContent += FString::Printf(TEXT("public:\n"));
	FileContent += FString::Printf(
		TEXT("\tinline static const TMap<int32, TSharedPtr<google::protobuf::Message>> RegisteredMessages{\n"));

	// 写入Map值
	if (MessageNamespace.IsEmpty())
	{
		for (const FString& Message : MessageArray)
		{
			FileContent += FString::Printf(
				TEXT("\t\t{FMessageIdentifies::%s, MakeShared<%s>()},\n"), *Message, *Message);
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
	FFileHelper::SaveStringToFile(FileContent, *RegisteredMessagesPath,
	                              FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
}

bool UMessageGenUtil::RunPyToCompileProto(const FString& PythonExecutable, const FString& PyPath,
                                          const FString& ProtoDir, const FString& CppOut,
                                          FString& OutStdOut, FString& OutStdErr)
{
	const FString CommandLineArgs = FString::Printf(TEXT("--proto_input=%s --cpp_out=%s"),
	                                                *ProtoDir, *CppOut);
	const FString ExeCommandLine = FString::Printf(TEXT("\"%s\" \"%s\""),
	                                               *PythonExecutable, *PyPath);

	FString OutStdOutStr;
	FString OutStdErrStr;

	int32 ReturnCode;
	FPlatformProcess::ExecProcess(*ExeCommandLine, *CommandLineArgs, &ReturnCode, &OutStdOutStr, &OutStdErrStr);

	OutStdOut = OutStdOutStr;
	OutStdErr = OutStdErrStr;
	return ReturnCode == 0;
}

TArray<FString> UMessageGenUtil::GetPbFileNames(const FString& Dir, const bool bIsCC)
{
	// 创建目录迭代器
	IFileManager& FileManager = IFileManager::Get();

	// 设置目录路径
	const FString SearchPath = FPaths::Combine(Dir, bIsCC ? TEXT("*.pb.cc") : TEXT("*.pb.h"));

	// 获取所有以 .pb.h 结尾的文件
	TArray<FString> PBFiles;
	FileManager.FindFiles(PBFiles, *SearchPath, true, false);

	// 遍历文件
	TArray<FString> Results;
	for (const FString& FilePath : PBFiles)
	{
		// 获取文件名称（不带后缀）
		Results.Add(FPaths::GetBaseFilename(FilePath).Replace(TEXT(".pb"), TEXT("")));
	}

	return Results;
}

FString UMessageGenUtil::GetPluginPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	const FString PluginPath = FPaths::ProjectPluginsDir().Append("ProtobufBlueprintSp");

	return PlatformFile.DirectoryExists(*PluginPath) ? PluginPath : FString();
}

FString UMessageGenUtil::GetMessageConstantPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	const FString ConstantDir = GetPluginPath().Append("/Source/ProtobufBlueprintSp/Public/Constant");

	return PlatformFile.DirectoryExists(*ConstantDir) ? ConstantDir : FString();
}

FString UMessageGenUtil::GetFMessageIdentifiesPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	const FString FmiPath = GetMessageConstantPath().Append("/FMessageIdentifies.h");

	if (!PlatformFile.FileExists(*FmiPath))
	{
		WriteMessageIdentifies(TMap<FString, int32>(), FmiPath, true);
	}

	return FmiPath;
}

FString UMessageGenUtil::GetFRegisteredMessagesPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	const FString FrmPath = GetMessageConstantPath().Append("/FRegisteredMessages.h");

	if (!PlatformFile.FileExists(*FrmPath))
	{
		WriteRegisteredMessages(
			TArray<FString>(),
			FrmPath,
			FString(),
			FString(),
			true
		);
	}

	return FrmPath;
}

FString UMessageGenUtil::GetEnginePythonPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	// 获取引擎根目录
	const FString EngineDir = FPaths::EngineDir();

	// 构建 Python 解释器路径
	FString PythonExePath = FPaths::Combine(*EngineDir, TEXT("Binaries/ThirdParty/Python3/{Platform}/python.exe"));

	// 替换 {Platform} 为当前平台（Win64、Win32等）
	PythonExePath.ReplaceInline(TEXT("{Platform}"), FPlatformProcess::GetBinariesSubdirectory());

	return PlatformFile.FileExists(*PythonExePath) ? PythonExePath : FString();
}

FString UMessageGenUtil::GetPyGenerateScriptPath()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	const FString ScriptPath = FPaths::Combine(GetPluginPath(),
		TEXT("/Source/ThirdParty/libprotobuf/tools/generate_for_ue.py"));

	return PlatformFile.FileExists(*ScriptPath) ? ScriptPath : FString();
}
