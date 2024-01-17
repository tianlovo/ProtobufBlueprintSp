// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/PropertyUtil.h"

bool FPropertyUtil::IsPropertyInCategory(const FProperty* Property, const FString& CategoryName)
{
	return Property->GetMetaData(TEXT("Category")).Equals(CategoryName);
}
