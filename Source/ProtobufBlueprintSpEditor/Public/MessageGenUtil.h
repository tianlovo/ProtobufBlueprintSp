// Author's Github: https://github.com/tianlovo

#pragma once

#include "CoreMinimal.h"
#include "MessageGenUtil.generated.h"

/**
 * Protobuf消息生成相关的工具类
 */
UCLASS()
class PROTOBUFBLUEPRINTSPEDITOR_API UMessageGenUtil : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * 读取FMessageIdentifies.h文件并获取消息名称与消息标识符的映射合集
	 * @param IdentifiesPath FMessageIdentifies.h文件路径
	 * @return 消息名称与消息标识符映射合集
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static TMap<FString, int32> ReadMessageIdentifies(const FString& IdentifiesPath);

	/**
	 * 将消息名称与消息标识符映射合集覆盖写入到FMessageIdentifies.h文件中
	 * @param MessageIdentifies 消息名称与消息标识符映射合集
	 * @param IdentifiesPath FMessageIdentifies.h文件路径
	 * @param bIsCreate 是否是创建文件
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static void WriteMessageIdentifies(const TMap<FString, int32>& MessageIdentifies,
		const FString& IdentifiesPath, const bool bIsCreate = false);

	/**
	 * 消息名称覆盖写入到FRegisteredMessages.h文件中
	 * @param MessageArray 消息名称数组
	 * @param RegisteredMessagesPath FRegisteredMessages.h文件路径
	 * @param PbPrefixPath .pb.h文件的前缀路径
	 * @param MessageNamespace 消息命名空间全称
	 * @param bIsCreate 是否是创建文件
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static void WriteRegisteredMessages(const TArray<FString>& MessageArray, const FString& RegisteredMessagesPath,
	                                    const FString& PbPrefixPath, const FString& MessageNamespace,
	                                    const bool bIsCreate = false);

	/**
	 * 运行py脚本以编译.proto文件
	 * @param PythonExecutable python.exe路径
	 * @param PyPath generate_for_ue.py路径
	 * @param ProtoDir 要编译的.proto文件路径
	 * @param CppOut 编译输出的路径
	 * @param OutStdOut 运行输出
	 * @param OutStdErr 运行错误输出
	 * @return 是否成功
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static bool RunPyToCompileProto(const FString& PythonExecutable, const FString& PyPath,
		const FString& ProtoDir, const FString& CppOut,
		FString& OutStdOut, FString& OutStdErr);

	/**
	 * 获取proto编译后的所有cpp文件名称
	 * @param Dir proto编译后的cpp目录
	 * @param bIsCC 是否为.pb.cc结尾(默认.pb.h)
	 * @return 文件名称数组
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static TArray<FString> GetPbFileNames(const FString& Dir, const bool bIsCC = false);

	///------------------------- Path Helper -------------------------
	
	/**
	 * 获取插件全路径
	 * @return 获取插件全路径
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetPluginPath();

	/**
	 * 获取消息常量定义路径(插件内)
	 * @return 消息常量定义路径(插件内)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetMessageConstantPath();

	/**
	 * 获取FMessageIdentifies.h文件路径
	 *
	 * 如果不存在自动创建
	 * @return FMessageIdentifies.h文件路径
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetFMessageIdentifiesPath();

	/**
	 * 获取FRegisteredMessages.h文件路径
	 *
	 * 如果不存在自动创建
	 * @return FRegisteredMessages.h文件路径
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetFRegisteredMessagesPath();

	/**
	 * 获取引擎自带的python.exe路径
	 * @return 引擎自带的python.exe路径
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetEnginePythonPath();

	/**
	 * 获取generate_for_ue.py路径
	 * @return generate_for_ue.py路径
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Editor|Protobuf|Util")
	static FString GetPyGenerateScriptPath();
};
