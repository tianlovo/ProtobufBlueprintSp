/*@ fixed */

#if defined(_MSC_VER)
  #pragma warning (disable:4018) // 'expression' : signed/unsigned mismatch
  #pragma warning (disable:4065) // switch statement contains 'default' but no 'case' labels
  #pragma warning (disable:4146) // unary minus operator applied to unsigned type, result still unsigned
  #pragma warning (disable:4244) // 'conversion' conversion from 'type1' to 'type2', possible loss of data
  #pragma warning (disable:4251) // 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
  #pragma warning (disable:4267) // 'var' : conversion from 'size_t' to 'type', possible loss of data
  #pragma warning (disable:4305) // 'identifier' : truncation from 'type1' to 'type2'
  #pragma warning (disable:4307) // 'operator' : integral constant overflow
  #pragma warning (disable:4309) // 'conversion' : truncation of constant value
  #pragma warning (disable:4334) // 'operator' : result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
  #pragma warning (disable:4355) // 'this' : used in base member initializer list
  #pragma warning (disable:4506) // no definition for inline function 'function'
  #pragma warning (disable:4800) // 'type' : forcing value to bool 'true' or 'false' (performance warning)
  #pragma warning (disable:4996) // The compiler encountered a deprecated declaration.
  #pragma warning (disable:4125) // decimal digit terminates octal escape sequence
#endif
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ExampleProto.proto

#include "ExampleProto.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace ProtobufBlueprintSp {
constexpr ExampleProto::ExampleProto(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : bool_vals_()
  , int32_vals_()
  , _int32_vals_cached_byte_size_(0)
  , int64_vals_()
  , _int64_vals_cached_byte_size_(0)
  , double_vals_()
  , string_vals_()
  , sub_protos_()
  , string_val_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , bytes_val_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , sub_proto_(nullptr)
  , bool_val_(false)
  , int32_val_(0)
  , int64_val_(int64_t{0})
  , double_val_(0){}
struct ExampleProtoDefaultTypeInternal {
  constexpr ExampleProtoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ExampleProtoDefaultTypeInternal() {}
  union {
    ExampleProto _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ExampleProtoDefaultTypeInternal _ExampleProto_default_instance_;
}  // namespace ProtobufBlueprintSp
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ExampleProto_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ExampleProto_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ExampleProto_2eproto = nullptr;

const uint32_t TableStruct_ExampleProto_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, bool_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, int32_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, int64_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, double_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, string_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, bytes_val_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, sub_proto_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, bool_vals_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, int32_vals_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, int64_vals_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, double_vals_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, string_vals_),
  PROTOBUF_FIELD_OFFSET(::ProtobufBlueprintSp::ExampleProto, sub_protos_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ProtobufBlueprintSp::ExampleProto)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ProtobufBlueprintSp::_ExampleProto_default_instance_),
};

const char descriptor_table_protodef_ExampleProto_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022ExampleProto.proto\022\023ProtobufBlueprintS"
  "p\032\025ExampleSubProto.proto\"\331\002\n\014ExampleProt"
  "o\022\020\n\010bool_val\030\001 \001(\010\022\021\n\tint32_val\030\002 \001(\005\022\021"
  "\n\tint64_val\030\003 \001(\003\022\022\n\ndouble_val\030\004 \001(\001\022\022\n"
  "\nstring_val\030\005 \001(\t\022\021\n\tbytes_val\030\006 \001(\014\0227\n\t"
  "sub_proto\030\007 \001(\0132$.ProtobufBlueprintSp.Ex"
  "ampleSubProto\022\021\n\tbool_vals\030\010 \003(\010\022\022\n\nint3"
  "2_vals\030\t \003(\005\022\022\n\nint64_vals\030\n \003(\003\022\023\n\013doub"
  "le_vals\030\013 \003(\001\022\023\n\013string_vals\030\014 \003(\t\0228\n\nsu"
  "b_protos\030\r \003(\0132$.ProtobufBlueprintSp.Exa"
  "mpleSubProtob\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_ExampleProto_2eproto_deps[1] = {
  &::descriptor_table_ExampleSubProto_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ExampleProto_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ExampleProto_2eproto = {
  false, false, 420, descriptor_table_protodef_ExampleProto_2eproto, "ExampleProto.proto", 
  &descriptor_table_ExampleProto_2eproto_once, descriptor_table_ExampleProto_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_ExampleProto_2eproto::offsets,
  file_level_metadata_ExampleProto_2eproto, file_level_enum_descriptors_ExampleProto_2eproto, file_level_service_descriptors_ExampleProto_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_ExampleProto_2eproto_getter() {
  return &descriptor_table_ExampleProto_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_ExampleProto_2eproto(&descriptor_table_ExampleProto_2eproto);
namespace ProtobufBlueprintSp {

// ===================================================================

class ExampleProto::_Internal {
 public:
  static const ::ProtobufBlueprintSp::ExampleSubProto& sub_proto(const ExampleProto* msg);
};

const ::ProtobufBlueprintSp::ExampleSubProto&
ExampleProto::_Internal::sub_proto(const ExampleProto* msg) {
  return *msg->sub_proto_;
}
void ExampleProto::clear_sub_proto() {
  if (GetArenaForAllocation() == nullptr && sub_proto_ != nullptr) {
    delete sub_proto_;
  }
  sub_proto_ = nullptr;
}
void ExampleProto::clear_sub_protos() {
  sub_protos_.Clear();
}
ExampleProto::ExampleProto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  bool_vals_(arena),
  int32_vals_(arena),
  int64_vals_(arena),
  double_vals_(arena),
  string_vals_(arena),
  sub_protos_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ProtobufBlueprintSp.ExampleProto)
}
ExampleProto::ExampleProto(const ExampleProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      bool_vals_(from.bool_vals_),
      int32_vals_(from.int32_vals_),
      int64_vals_(from.int64_vals_),
      double_vals_(from.double_vals_),
      string_vals_(from.string_vals_),
      sub_protos_(from.sub_protos_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  string_val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    string_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_string_val().empty()) {
    string_val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_string_val(), 
      GetArenaForAllocation());
  }
  bytes_val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    bytes_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_bytes_val().empty()) {
    bytes_val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_bytes_val(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_sub_proto()) {
    sub_proto_ = new ::ProtobufBlueprintSp::ExampleSubProto(*from.sub_proto_);
  } else {
    sub_proto_ = nullptr;
  }
  ::memcpy(&bool_val_, &from.bool_val_,
    static_cast<size_t>(reinterpret_cast<char*>(&double_val_) -
    reinterpret_cast<char*>(&bool_val_)) + sizeof(double_val_));
  // @@protoc_insertion_point(copy_constructor:ProtobufBlueprintSp.ExampleProto)
}

inline void ExampleProto::SharedCtor() {
string_val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  string_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
bytes_val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  bytes_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&sub_proto_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&double_val_) -
    reinterpret_cast<char*>(&sub_proto_)) + sizeof(double_val_));
}

ExampleProto::~ExampleProto() {
  // @@protoc_insertion_point(destructor:ProtobufBlueprintSp.ExampleProto)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ExampleProto::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  string_val_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  bytes_val_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete sub_proto_;
}

void ExampleProto::ArenaDtor(void* object) {
  ExampleProto* _this = reinterpret_cast< ExampleProto* >(object);
  (void)_this;
}
void ExampleProto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ExampleProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ExampleProto::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtobufBlueprintSp.ExampleProto)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  bool_vals_.Clear();
  int32_vals_.Clear();
  int64_vals_.Clear();
  double_vals_.Clear();
  string_vals_.Clear();
  sub_protos_.Clear();
  string_val_.ClearToEmpty();
  bytes_val_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && sub_proto_ != nullptr) {
    delete sub_proto_;
  }
  sub_proto_ = nullptr;
  ::memset(&bool_val_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&double_val_) -
      reinterpret_cast<char*>(&bool_val_)) + sizeof(double_val_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ExampleProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool bool_val = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          bool_val_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 int32_val = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          int32_val_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 int64_val = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          int64_val_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double double_val = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          double_val_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // string string_val = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_string_val();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ProtobufBlueprintSp.ExampleProto.string_val"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes bytes_val = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          auto str = _internal_mutable_bytes_val();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .ProtobufBlueprintSp.ExampleSubProto sub_proto = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr = ctx->ParseMessage(_internal_mutable_sub_proto(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated bool bool_vals = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 66)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedBoolParser(_internal_mutable_bool_vals(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 64) {
          _internal_add_bool_vals(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated int32 int32_vals = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 74)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_int32_vals(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 72) {
          _internal_add_int32_vals(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated int64 int64_vals = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt64Parser(_internal_mutable_int64_vals(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 80) {
          _internal_add_int64_vals(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated double double_vals = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 90)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_double_vals(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 89) {
          _internal_add_double_vals(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated string string_vals = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 98)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_string_vals();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ProtobufBlueprintSp.ExampleProto.string_vals"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<98>(ptr));
        } else
          goto handle_unusual;
        continue;
      // repeated .ProtobufBlueprintSp.ExampleSubProto sub_protos = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 106)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_sub_protos(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<106>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ExampleProto::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtobufBlueprintSp.ExampleProto)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool bool_val = 1;
  if (this->_internal_bool_val() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_bool_val(), target);
  }

  // int32 int32_val = 2;
  if (this->_internal_int32_val() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_int32_val(), target);
  }

  // int64 int64_val = 3;
  if (this->_internal_int64_val() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_int64_val(), target);
  }

  // double double_val = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_double_val = this->_internal_double_val();
  uint64_t raw_double_val;
  memcpy(&raw_double_val, &tmp_double_val, sizeof(tmp_double_val));
  if (raw_double_val != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(4, this->_internal_double_val(), target);
  }

  // string string_val = 5;
  if (!this->_internal_string_val().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_string_val().data(), static_cast<int>(this->_internal_string_val().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ProtobufBlueprintSp.ExampleProto.string_val");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_string_val(), target);
  }

  // bytes bytes_val = 6;
  if (!this->_internal_bytes_val().empty()) {
    target = stream->WriteBytesMaybeAliased(
        6, this->_internal_bytes_val(), target);
  }

  // .ProtobufBlueprintSp.ExampleSubProto sub_proto = 7;
  if (this->_internal_has_sub_proto()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        7, _Internal::sub_proto(this), target, stream);
  }

  // repeated bool bool_vals = 8;
  if (this->_internal_bool_vals_size() > 0) {
    target = stream->WriteFixedPacked(8, _internal_bool_vals(), target);
  }

  // repeated int32 int32_vals = 9;
  {
    int byte_size = _int32_vals_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          9, _internal_int32_vals(), byte_size, target);
    }
  }

  // repeated int64 int64_vals = 10;
  {
    int byte_size = _int64_vals_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt64Packed(
          10, _internal_int64_vals(), byte_size, target);
    }
  }

  // repeated double double_vals = 11;
  if (this->_internal_double_vals_size() > 0) {
    target = stream->WriteFixedPacked(11, _internal_double_vals(), target);
  }

  // repeated string string_vals = 12;
  for (int i = 0, n = this->_internal_string_vals_size(); i < n; i++) {
    const auto& s = this->_internal_string_vals(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ProtobufBlueprintSp.ExampleProto.string_vals");
    target = stream->WriteString(12, s, target);
  }

  // repeated .ProtobufBlueprintSp.ExampleSubProto sub_protos = 13;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_sub_protos_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(13, this->_internal_sub_protos(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ProtobufBlueprintSp.ExampleProto)
  return target;
}

size_t ExampleProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ProtobufBlueprintSp.ExampleProto)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bool bool_vals = 8;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_bool_vals_size());
    size_t data_size = 1UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // repeated int32 int32_vals = 9;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->int32_vals_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _int32_vals_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated int64 int64_vals = 10;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int64Size(this->int64_vals_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _int64_vals_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated double double_vals = 11;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_double_vals_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // repeated string string_vals = 12;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(string_vals_.size());
  for (int i = 0, n = string_vals_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      string_vals_.Get(i));
  }

  // repeated .ProtobufBlueprintSp.ExampleSubProto sub_protos = 13;
  total_size += 1UL * this->_internal_sub_protos_size();
  for (const auto& msg : this->sub_protos_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string string_val = 5;
  if (!this->_internal_string_val().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_string_val());
  }

  // bytes bytes_val = 6;
  if (!this->_internal_bytes_val().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_bytes_val());
  }

  // .ProtobufBlueprintSp.ExampleSubProto sub_proto = 7;
  if (this->_internal_has_sub_proto()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *sub_proto_);
  }

  // bool bool_val = 1;
  if (this->_internal_bool_val() != 0) {
    total_size += 1 + 1;
  }

  // int32 int32_val = 2;
  if (this->_internal_int32_val() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_int32_val());
  }

  // int64 int64_val = 3;
  if (this->_internal_int64_val() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_int64_val());
  }

  // double double_val = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_double_val = this->_internal_double_val();
  uint64_t raw_double_val;
  memcpy(&raw_double_val, &tmp_double_val, sizeof(tmp_double_val));
  if (raw_double_val != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ExampleProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ExampleProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ExampleProto::GetClassData() const { return &_class_data_; }

void ExampleProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ExampleProto *>(to)->MergeFrom(
      static_cast<const ExampleProto &>(from));
}


void ExampleProto::MergeFrom(const ExampleProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtobufBlueprintSp.ExampleProto)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  bool_vals_.MergeFrom(from.bool_vals_);
  int32_vals_.MergeFrom(from.int32_vals_);
  int64_vals_.MergeFrom(from.int64_vals_);
  double_vals_.MergeFrom(from.double_vals_);
  string_vals_.MergeFrom(from.string_vals_);
  sub_protos_.MergeFrom(from.sub_protos_);
  if (!from._internal_string_val().empty()) {
    _internal_set_string_val(from._internal_string_val());
  }
  if (!from._internal_bytes_val().empty()) {
    _internal_set_bytes_val(from._internal_bytes_val());
  }
  if (from._internal_has_sub_proto()) {
    _internal_mutable_sub_proto()->::ProtobufBlueprintSp::ExampleSubProto::MergeFrom(from._internal_sub_proto());
  }
  if (from._internal_bool_val() != 0) {
    _internal_set_bool_val(from._internal_bool_val());
  }
  if (from._internal_int32_val() != 0) {
    _internal_set_int32_val(from._internal_int32_val());
  }
  if (from._internal_int64_val() != 0) {
    _internal_set_int64_val(from._internal_int64_val());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_double_val = from._internal_double_val();
  uint64_t raw_double_val;
  memcpy(&raw_double_val, &tmp_double_val, sizeof(tmp_double_val));
  if (raw_double_val != 0) {
    _internal_set_double_val(from._internal_double_val());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ExampleProto::CopyFrom(const ExampleProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtobufBlueprintSp.ExampleProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExampleProto::IsInitialized() const {
  return true;
}

void ExampleProto::InternalSwap(ExampleProto* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  bool_vals_.InternalSwap(&other->bool_vals_);
  int32_vals_.InternalSwap(&other->int32_vals_);
  int64_vals_.InternalSwap(&other->int64_vals_);
  double_vals_.InternalSwap(&other->double_vals_);
  string_vals_.InternalSwap(&other->string_vals_);
  sub_protos_.InternalSwap(&other->sub_protos_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &string_val_, lhs_arena,
      &other->string_val_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &bytes_val_, lhs_arena,
      &other->bytes_val_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ExampleProto, double_val_)
      + sizeof(ExampleProto::double_val_)
      - PROTOBUF_FIELD_OFFSET(ExampleProto, sub_proto_)>(
          reinterpret_cast<char*>(&sub_proto_),
          reinterpret_cast<char*>(&other->sub_proto_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ExampleProto::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ExampleProto_2eproto_getter, &descriptor_table_ExampleProto_2eproto_once,
      file_level_metadata_ExampleProto_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace ProtobufBlueprintSp
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ProtobufBlueprintSp::ExampleProto* Arena::CreateMaybeMessage< ::ProtobufBlueprintSp::ExampleProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ProtobufBlueprintSp::ExampleProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>