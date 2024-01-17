// Author's Github: https://github.com/tianlovo


#include "Util/PropertyUtil.h"

bool FPropertyUtil::IsPropertyInCategory(const FProperty* Property, const FString& CategoryName)
{
	return Property->GetMetaData(TEXT("Category")).Equals(CategoryName);
}
