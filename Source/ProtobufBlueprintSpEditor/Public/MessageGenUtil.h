// Author's Github: https://github.com/tianlovo

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static void WriteMessageIdentifies(const TMap<FString, int32>& MessageIdentifies, const FString& IdentifiesPath);

	/**
	 * 消息名称覆盖写入到FRegisteredMessages.h文件中
	 * @param MessageArray 消息名称数组
	 * @param RegisteredMessagesPath FRegisteredMessages.h文件路径
	 * @param PbPrefixPath .pb.h文件的前缀路径
	 * @param MessageNamespace 消息命名空间全称
	 */
	UFUNCTION(BlueprintCallable, Category="Editor|Protobuf|Util")
	static void WriteRegisteredMessages(const TArray<FString>& MessageArray, const FString& RegisteredMessagesPath,
	                                    const FString& PbPrefixPath, const FString& MessageNamespace);
};
