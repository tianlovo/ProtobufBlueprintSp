// Author's Github: https://github.com/tianlovo

#pragma once

#include "CoreMinimal.h"
#include "ProtobufMessage.h"
#include "google/protobuf/message.h"

using namespace google::protobuf;

/**
 * Protobuf的工具类
 */
class PROTOBUFBLUEPRINTSP_API FProtobufUtil
{
	FProtobufUtil() {}
	~FProtobufUtil() {}

public:
	/**
	 * 将字符串转化为snake_case风格字符串
	 * @param InputString 输入字符串
	 * @return snake_case风格字符串
	 */
	static FString ToSnakeCase(const FString& InputString);
	
	/**
	 * 通过UE的属性设置Protobuf消息的属性
	 *
	 * 注意：.proto文件定义的变量名称要为snake_case风格，否则无法设置属性
	 * @param Object UE对象
	 * @param ObjectProperty UE的属性对象
	 * @param FoundMessage 从RegisteredMessages映射里找到的具体消息对象
	 * @param BuildMessage 新建的消息对象(从generated_factory生成)
	 */
	static void SetProtobufByUE(const UProtobufMessage* Object, const FProperty* ObjectProperty,
		Message* FoundMessage, Message* BuildMessage);

	/**
	 * 通过Protobuf消息的属性设置UE的属性
	 *
	 * 注意：.proto文件定义的变量名称要为snake_case风格，否则无法设置属性
	 * @param Object UE对象
	 * @param ObjectProperty UE的属性对象
	 * @param FoundMessage 从RegisteredMessages映射里找到的具体消息对象
	 */
	static void SetUEByProtobuf(UProtobufMessage* Object, const FProperty* ObjectProperty, Message* FoundMessage);
};
