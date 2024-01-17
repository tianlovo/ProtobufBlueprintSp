// Author's Github: https://github.com/tianlovo

#pragma once

#include "CoreMinimal.h"

/**
 * UObject的属性工具类
 */
class PROTOBUFBLUEPRINTSP_API FPropertyUtil
{
	FPropertyUtil() {}
	~FPropertyUtil() {}

public:
	/**
	 * 判断属性是否在给定分类中
	 * @param Property 属性对象
	 * @param CategoryName 分类名称
	 * @return 是否在给定分类中
	 */
	inline static bool IsPropertyInCategory(const FProperty* Property, const FString& CategoryName);
};
