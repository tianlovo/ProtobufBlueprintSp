#pragma once

#include "FMessageIdentifies.h"
#include "google/protobuf/message.h"


class FRegisteredMessages
{
public:
	inline static const TMap<int32, TSharedPtr<google::protobuf::Message>> RegisteredMessages{
	};
};
