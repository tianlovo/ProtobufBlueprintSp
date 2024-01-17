#pragma once

#include "FMessageIdentifies.h"
#include "google/protobuf/message.h"

#include "ProtoGenExample/ExampleProto.pb.h"
#include "ProtoGenExample/ExampleSubProto.pb.h"

class FRegisteredMessages
{
public:
	inline static const TMap<int32, TSharedPtr<google::protobuf::Message>> RegisteredMessages{
		{FMessageIdentifies::ExampleProto, MakeShared<ProtobufBlueprintSp::ExampleProto>()},
		{FMessageIdentifies::ExampleSubProto, MakeShared<ProtobufBlueprintSp::ExampleSubProto>()},
	};
};
