// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProtobufMessage.generated.h"

/**
 * Protobuf消息与蓝图交互的类
 */
UCLASS(Abstract, Blueprintable)
class PROTOBUFBLUEPRINTSP_API UProtobufMessage : public UObject
{
	GENERATED_BODY()

protected:
	// 消息标识符 与 蓝图消息类型 的映射
	static TMap<int32, TSubclassOf<UProtobufMessage>> IdentifyMap;
	
public:
	virtual void PostInitProperties() override;

	// 标识唯一消息类
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Protobuf|Message")
	int32 Identify;

	/**
	 * 初始化 消息标识符 与 蓝图消息类型 的映射
	 */
	UFUNCTION(BlueprintCallable, Category="Protobuf|Message")
	static void InitIdentifyMap();
	
	/**
	 * 创建一个消息对象
	 * @param MessageClass 消息类型
	 * @return 创建的消息对象
	 */
	UFUNCTION(BlueprintCallable, Category="Protobuf|Util")
	static UProtobufMessage* CreateMessage(const TSubclassOf<UProtobufMessage> MessageClass);

	/**
	 * 将消息对象转换成Protobuf消息后序列化为字节数组
	 * @param Message 消息对象
	 * @return Protobuf序列化字节数组
	 */
	UFUNCTION(BlueprintCallable, Category="Protobuf|Util")
	static TArray<uint8> ToProtobufBytes(const UProtobufMessage* Message);

	/**
	 * 将Protobuf消息后序列化为字节数组解析为消息对象
	 * @param MessageIdentify 消息类唯一标识符
	 * @param ProtobufData Protobuf序列化字节数组
	 * @param Message 消息对象(解析后自动设置该对象的属性)
	 * @return 是否解析成功
	 */
	UFUNCTION(BlueprintCallable, Category="Protobuf|Util")
	static bool FromProtobufBytes(const int32 MessageIdentify, TArray<uint8> ProtobufData, UProtobufMessage* Message);

	/**
	 * 从Protobuf消息序列化字节数组生成消息对象
	 * @param MessageIdentify 消息类唯一标识符
	 * @param ProtobufData Protobuf序列化字节数组
	 * @param Message 创建的解析后的消息对象
	 * @return 是否成功解析
	 */
	UFUNCTION(BlueprintCallable, Category="Protobuf|Util")
	static bool CreateMessageByProtobuf(const int32 MessageIdentify, const TArray<uint8> ProtobufData, UProtobufMessage*& Message);
};
