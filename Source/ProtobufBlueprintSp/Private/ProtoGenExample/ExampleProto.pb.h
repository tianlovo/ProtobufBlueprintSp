/*@ fixed */

#if defined(_MSC_VER)
  #pragma warning (disable:4946) // reinterpret_cast used between related classes: 'class1' and 'class2'
#endif
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ExampleProto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ExampleProto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ExampleProto_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "ExampleSubProto.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ExampleProto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ExampleProto_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ExampleProto_2eproto;
namespace ProtobufBlueprintSp {
class ExampleProto;
struct ExampleProtoDefaultTypeInternal;
extern ExampleProtoDefaultTypeInternal _ExampleProto_default_instance_;
}  // namespace ProtobufBlueprintSp
PROTOBUF_NAMESPACE_OPEN
template<> ::ProtobufBlueprintSp::ExampleProto* Arena::CreateMaybeMessage<::ProtobufBlueprintSp::ExampleProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ProtobufBlueprintSp {

// ===================================================================

class ExampleProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProtobufBlueprintSp.ExampleProto) */ {
 public:
  inline ExampleProto() : ExampleProto(nullptr) {}
  ~ExampleProto() override;
  explicit constexpr ExampleProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ExampleProto(const ExampleProto& from);
  ExampleProto(ExampleProto&& from) noexcept
    : ExampleProto() {
    *this = ::std::move(from);
  }

  inline ExampleProto& operator=(const ExampleProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline ExampleProto& operator=(ExampleProto&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ExampleProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const ExampleProto* internal_default_instance() {
    return reinterpret_cast<const ExampleProto*>(
               &_ExampleProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ExampleProto& a, ExampleProto& b) {
    a.Swap(&b);
  }
  inline void Swap(ExampleProto* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ExampleProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ExampleProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ExampleProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ExampleProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ExampleProto& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ExampleProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProtobufBlueprintSp.ExampleProto";
  }
  protected:
  explicit ExampleProto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBoolValsFieldNumber = 8,
    kInt32ValsFieldNumber = 9,
    kInt64ValsFieldNumber = 10,
    kDoubleValsFieldNumber = 11,
    kStringValsFieldNumber = 12,
    kSubProtosFieldNumber = 13,
    kStringValFieldNumber = 5,
    kBytesValFieldNumber = 6,
    kSubProtoFieldNumber = 7,
    kBoolValFieldNumber = 1,
    kInt32ValFieldNumber = 2,
    kInt64ValFieldNumber = 3,
    kDoubleValFieldNumber = 4,
  };
  // repeated bool bool_vals = 8;
  int bool_vals_size() const;
  private:
  int _internal_bool_vals_size() const;
  public:
  void clear_bool_vals();
  private:
  bool _internal_bool_vals(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >&
      _internal_bool_vals() const;
  void _internal_add_bool_vals(bool value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >*
      _internal_mutable_bool_vals();
  public:
  bool bool_vals(int index) const;
  void set_bool_vals(int index, bool value);
  void add_bool_vals(bool value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >&
      bool_vals() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >*
      mutable_bool_vals();

  // repeated int32 int32_vals = 9;
  int int32_vals_size() const;
  private:
  int _internal_int32_vals_size() const;
  public:
  void clear_int32_vals();
  private:
  int32_t _internal_int32_vals(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_int32_vals() const;
  void _internal_add_int32_vals(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_int32_vals();
  public:
  int32_t int32_vals(int index) const;
  void set_int32_vals(int index, int32_t value);
  void add_int32_vals(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      int32_vals() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_int32_vals();

  // repeated int64 int64_vals = 10;
  int int64_vals_size() const;
  private:
  int _internal_int64_vals_size() const;
  public:
  void clear_int64_vals();
  private:
  int64_t _internal_int64_vals(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_int64_vals() const;
  void _internal_add_int64_vals(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_int64_vals();
  public:
  int64_t int64_vals(int index) const;
  void set_int64_vals(int index, int64_t value);
  void add_int64_vals(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      int64_vals() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_int64_vals();

  // repeated double double_vals = 11;
  int double_vals_size() const;
  private:
  int _internal_double_vals_size() const;
  public:
  void clear_double_vals();
  private:
  double _internal_double_vals(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_double_vals() const;
  void _internal_add_double_vals(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_double_vals();
  public:
  double double_vals(int index) const;
  void set_double_vals(int index, double value);
  void add_double_vals(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      double_vals() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_double_vals();

  // repeated string string_vals = 12;
  int string_vals_size() const;
  private:
  int _internal_string_vals_size() const;
  public:
  void clear_string_vals();
  const std::string& string_vals(int index) const;
  std::string* mutable_string_vals(int index);
  void set_string_vals(int index, const std::string& value);
  void set_string_vals(int index, std::string&& value);
  void set_string_vals(int index, const char* value);
  void set_string_vals(int index, const char* value, size_t size);
  std::string* add_string_vals();
  void add_string_vals(const std::string& value);
  void add_string_vals(std::string&& value);
  void add_string_vals(const char* value);
  void add_string_vals(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& string_vals() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_string_vals();
  private:
  const std::string& _internal_string_vals(int index) const;
  std::string* _internal_add_string_vals();
  public:

  // repeated .ProtobufBlueprintSp.ExampleSubProto sub_protos = 13;
  int sub_protos_size() const;
  private:
  int _internal_sub_protos_size() const;
  public:
  void clear_sub_protos();
  ::ProtobufBlueprintSp::ExampleSubProto* mutable_sub_protos(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtobufBlueprintSp::ExampleSubProto >*
      mutable_sub_protos();
  private:
  const ::ProtobufBlueprintSp::ExampleSubProto& _internal_sub_protos(int index) const;
  ::ProtobufBlueprintSp::ExampleSubProto* _internal_add_sub_protos();
  public:
  const ::ProtobufBlueprintSp::ExampleSubProto& sub_protos(int index) const;
  ::ProtobufBlueprintSp::ExampleSubProto* add_sub_protos();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtobufBlueprintSp::ExampleSubProto >&
      sub_protos() const;

  // string string_val = 5;
  void clear_string_val();
  const std::string& string_val() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_string_val(ArgT0&& arg0, ArgT... args);
  std::string* mutable_string_val();
  PROTOBUF_NODISCARD std::string* release_string_val();
  void set_allocated_string_val(std::string* string_val);
  private:
  const std::string& _internal_string_val() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_string_val(const std::string& value);
  std::string* _internal_mutable_string_val();
  public:

  // bytes bytes_val = 6;
  void clear_bytes_val();
  const std::string& bytes_val() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_bytes_val(ArgT0&& arg0, ArgT... args);
  std::string* mutable_bytes_val();
  PROTOBUF_NODISCARD std::string* release_bytes_val();
  void set_allocated_bytes_val(std::string* bytes_val);
  private:
  const std::string& _internal_bytes_val() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_bytes_val(const std::string& value);
  std::string* _internal_mutable_bytes_val();
  public:

  // .ProtobufBlueprintSp.ExampleSubProto sub_proto = 7;
  bool has_sub_proto() const;
  private:
  bool _internal_has_sub_proto() const;
  public:
  void clear_sub_proto();
  const ::ProtobufBlueprintSp::ExampleSubProto& sub_proto() const;
  PROTOBUF_NODISCARD ::ProtobufBlueprintSp::ExampleSubProto* release_sub_proto();
  ::ProtobufBlueprintSp::ExampleSubProto* mutable_sub_proto();
  void set_allocated_sub_proto(::ProtobufBlueprintSp::ExampleSubProto* sub_proto);
  private:
  const ::ProtobufBlueprintSp::ExampleSubProto& _internal_sub_proto() const;
  ::ProtobufBlueprintSp::ExampleSubProto* _internal_mutable_sub_proto();
  public:
  void unsafe_arena_set_allocated_sub_proto(
      ::ProtobufBlueprintSp::ExampleSubProto* sub_proto);
  ::ProtobufBlueprintSp::ExampleSubProto* unsafe_arena_release_sub_proto();

  // bool bool_val = 1;
  void clear_bool_val();
  bool bool_val() const;
  void set_bool_val(bool value);
  private:
  bool _internal_bool_val() const;
  void _internal_set_bool_val(bool value);
  public:

  // int32 int32_val = 2;
  void clear_int32_val();
  int32_t int32_val() const;
  void set_int32_val(int32_t value);
  private:
  int32_t _internal_int32_val() const;
  void _internal_set_int32_val(int32_t value);
  public:

  // int64 int64_val = 3;
  void clear_int64_val();
  int64_t int64_val() const;
  void set_int64_val(int64_t value);
  private:
  int64_t _internal_int64_val() const;
  void _internal_set_int64_val(int64_t value);
  public:

  // double double_val = 4;
  void clear_double_val();
  double double_val() const;
  void set_double_val(double value);
  private:
  double _internal_double_val() const;
  void _internal_set_double_val(double value);
  public:

  // @@protoc_insertion_point(class_scope:ProtobufBlueprintSp.ExampleProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool > bool_vals_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > int32_vals_;
  mutable std::atomic<int> _int32_vals_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > int64_vals_;
  mutable std::atomic<int> _int64_vals_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > double_vals_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> string_vals_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtobufBlueprintSp::ExampleSubProto > sub_protos_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_val_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr bytes_val_;
  ::ProtobufBlueprintSp::ExampleSubProto* sub_proto_;
  bool bool_val_;
  int32_t int32_val_;
  int64_t int64_val_;
  double double_val_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ExampleProto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ExampleProto

// bool bool_val = 1;
inline void ExampleProto::clear_bool_val() {
  bool_val_ = false;
}
inline bool ExampleProto::_internal_bool_val() const {
  return bool_val_;
}
inline bool ExampleProto::bool_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.bool_val)
  return _internal_bool_val();
}
inline void ExampleProto::_internal_set_bool_val(bool value) {
  
  bool_val_ = value;
}
inline void ExampleProto::set_bool_val(bool value) {
  _internal_set_bool_val(value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.bool_val)
}

// int32 int32_val = 2;
inline void ExampleProto::clear_int32_val() {
  int32_val_ = 0;
}
inline int32_t ExampleProto::_internal_int32_val() const {
  return int32_val_;
}
inline int32_t ExampleProto::int32_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.int32_val)
  return _internal_int32_val();
}
inline void ExampleProto::_internal_set_int32_val(int32_t value) {
  
  int32_val_ = value;
}
inline void ExampleProto::set_int32_val(int32_t value) {
  _internal_set_int32_val(value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.int32_val)
}

// int64 int64_val = 3;
inline void ExampleProto::clear_int64_val() {
  int64_val_ = int64_t{0};
}
inline int64_t ExampleProto::_internal_int64_val() const {
  return int64_val_;
}
inline int64_t ExampleProto::int64_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.int64_val)
  return _internal_int64_val();
}
inline void ExampleProto::_internal_set_int64_val(int64_t value) {
  
  int64_val_ = value;
}
inline void ExampleProto::set_int64_val(int64_t value) {
  _internal_set_int64_val(value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.int64_val)
}

// double double_val = 4;
inline void ExampleProto::clear_double_val() {
  double_val_ = 0;
}
inline double ExampleProto::_internal_double_val() const {
  return double_val_;
}
inline double ExampleProto::double_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.double_val)
  return _internal_double_val();
}
inline void ExampleProto::_internal_set_double_val(double value) {
  
  double_val_ = value;
}
inline void ExampleProto::set_double_val(double value) {
  _internal_set_double_val(value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.double_val)
}

// string string_val = 5;
inline void ExampleProto::clear_string_val() {
  string_val_.ClearToEmpty();
}
inline const std::string& ExampleProto::string_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.string_val)
  return _internal_string_val();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ExampleProto::set_string_val(ArgT0&& arg0, ArgT... args) {
 
 string_val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.string_val)
}
inline std::string* ExampleProto::mutable_string_val() {
  std::string* _s = _internal_mutable_string_val();
  // @@protoc_insertion_point(field_mutable:ProtobufBlueprintSp.ExampleProto.string_val)
  return _s;
}
inline const std::string& ExampleProto::_internal_string_val() const {
  return string_val_.Get();
}
inline void ExampleProto::_internal_set_string_val(const std::string& value) {
  
  string_val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ExampleProto::_internal_mutable_string_val() {
  
  return string_val_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ExampleProto::release_string_val() {
  // @@protoc_insertion_point(field_release:ProtobufBlueprintSp.ExampleProto.string_val)
  return string_val_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ExampleProto::set_allocated_string_val(std::string* string_val) {
  if (string_val != nullptr) {
    
  } else {
    
  }
  string_val_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), string_val,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (string_val_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    string_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ProtobufBlueprintSp.ExampleProto.string_val)
}

// bytes bytes_val = 6;
inline void ExampleProto::clear_bytes_val() {
  bytes_val_.ClearToEmpty();
}
inline const std::string& ExampleProto::bytes_val() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.bytes_val)
  return _internal_bytes_val();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ExampleProto::set_bytes_val(ArgT0&& arg0, ArgT... args) {
 
 bytes_val_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.bytes_val)
}
inline std::string* ExampleProto::mutable_bytes_val() {
  std::string* _s = _internal_mutable_bytes_val();
  // @@protoc_insertion_point(field_mutable:ProtobufBlueprintSp.ExampleProto.bytes_val)
  return _s;
}
inline const std::string& ExampleProto::_internal_bytes_val() const {
  return bytes_val_.Get();
}
inline void ExampleProto::_internal_set_bytes_val(const std::string& value) {
  
  bytes_val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ExampleProto::_internal_mutable_bytes_val() {
  
  return bytes_val_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ExampleProto::release_bytes_val() {
  // @@protoc_insertion_point(field_release:ProtobufBlueprintSp.ExampleProto.bytes_val)
  return bytes_val_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ExampleProto::set_allocated_bytes_val(std::string* bytes_val) {
  if (bytes_val != nullptr) {
    
  } else {
    
  }
  bytes_val_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), bytes_val,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (bytes_val_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    bytes_val_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ProtobufBlueprintSp.ExampleProto.bytes_val)
}

// .ProtobufBlueprintSp.ExampleSubProto sub_proto = 7;
inline bool ExampleProto::_internal_has_sub_proto() const {
  return this != internal_default_instance() && sub_proto_ != nullptr;
}
inline bool ExampleProto::has_sub_proto() const {
  return _internal_has_sub_proto();
}
inline const ::ProtobufBlueprintSp::ExampleSubProto& ExampleProto::_internal_sub_proto() const {
  const ::ProtobufBlueprintSp::ExampleSubProto* p = sub_proto_;
  return p != nullptr ? *p : reinterpret_cast<const ::ProtobufBlueprintSp::ExampleSubProto&>(
      ::ProtobufBlueprintSp::_ExampleSubProto_default_instance_);
}
inline const ::ProtobufBlueprintSp::ExampleSubProto& ExampleProto::sub_proto() const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.sub_proto)
  return _internal_sub_proto();
}
inline void ExampleProto::unsafe_arena_set_allocated_sub_proto(
    ::ProtobufBlueprintSp::ExampleSubProto* sub_proto) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(sub_proto_);
  }
  sub_proto_ = sub_proto;
  if (sub_proto) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:ProtobufBlueprintSp.ExampleProto.sub_proto)
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::release_sub_proto() {
  
  ::ProtobufBlueprintSp::ExampleSubProto* temp = sub_proto_;
  sub_proto_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::unsafe_arena_release_sub_proto() {
  // @@protoc_insertion_point(field_release:ProtobufBlueprintSp.ExampleProto.sub_proto)
  
  ::ProtobufBlueprintSp::ExampleSubProto* temp = sub_proto_;
  sub_proto_ = nullptr;
  return temp;
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::_internal_mutable_sub_proto() {
  
  if (sub_proto_ == nullptr) {
    auto* p = CreateMaybeMessage<::ProtobufBlueprintSp::ExampleSubProto>(GetArenaForAllocation());
    sub_proto_ = p;
  }
  return sub_proto_;
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::mutable_sub_proto() {
  ::ProtobufBlueprintSp::ExampleSubProto* _msg = _internal_mutable_sub_proto();
  // @@protoc_insertion_point(field_mutable:ProtobufBlueprintSp.ExampleProto.sub_proto)
  return _msg;
}
inline void ExampleProto::set_allocated_sub_proto(::ProtobufBlueprintSp::ExampleSubProto* sub_proto) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(sub_proto_);
  }
  if (sub_proto) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(sub_proto));
    if (message_arena != submessage_arena) {
      sub_proto = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, sub_proto, submessage_arena);
    }
    
  } else {
    
  }
  sub_proto_ = sub_proto;
  // @@protoc_insertion_point(field_set_allocated:ProtobufBlueprintSp.ExampleProto.sub_proto)
}

// repeated bool bool_vals = 8;
inline int ExampleProto::_internal_bool_vals_size() const {
  return bool_vals_.size();
}
inline int ExampleProto::bool_vals_size() const {
  return _internal_bool_vals_size();
}
inline void ExampleProto::clear_bool_vals() {
  bool_vals_.Clear();
}
inline bool ExampleProto::_internal_bool_vals(int index) const {
  return bool_vals_.Get(index);
}
inline bool ExampleProto::bool_vals(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.bool_vals)
  return _internal_bool_vals(index);
}
inline void ExampleProto::set_bool_vals(int index, bool value) {
  bool_vals_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.bool_vals)
}
inline void ExampleProto::_internal_add_bool_vals(bool value) {
  bool_vals_.Add(value);
}
inline void ExampleProto::add_bool_vals(bool value) {
  _internal_add_bool_vals(value);
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.bool_vals)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >&
ExampleProto::_internal_bool_vals() const {
  return bool_vals_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >&
ExampleProto::bool_vals() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.bool_vals)
  return _internal_bool_vals();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >*
ExampleProto::_internal_mutable_bool_vals() {
  return &bool_vals_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< bool >*
ExampleProto::mutable_bool_vals() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.bool_vals)
  return _internal_mutable_bool_vals();
}

// repeated int32 int32_vals = 9;
inline int ExampleProto::_internal_int32_vals_size() const {
  return int32_vals_.size();
}
inline int ExampleProto::int32_vals_size() const {
  return _internal_int32_vals_size();
}
inline void ExampleProto::clear_int32_vals() {
  int32_vals_.Clear();
}
inline int32_t ExampleProto::_internal_int32_vals(int index) const {
  return int32_vals_.Get(index);
}
inline int32_t ExampleProto::int32_vals(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.int32_vals)
  return _internal_int32_vals(index);
}
inline void ExampleProto::set_int32_vals(int index, int32_t value) {
  int32_vals_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.int32_vals)
}
inline void ExampleProto::_internal_add_int32_vals(int32_t value) {
  int32_vals_.Add(value);
}
inline void ExampleProto::add_int32_vals(int32_t value) {
  _internal_add_int32_vals(value);
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.int32_vals)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
ExampleProto::_internal_int32_vals() const {
  return int32_vals_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
ExampleProto::int32_vals() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.int32_vals)
  return _internal_int32_vals();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
ExampleProto::_internal_mutable_int32_vals() {
  return &int32_vals_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
ExampleProto::mutable_int32_vals() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.int32_vals)
  return _internal_mutable_int32_vals();
}

// repeated int64 int64_vals = 10;
inline int ExampleProto::_internal_int64_vals_size() const {
  return int64_vals_.size();
}
inline int ExampleProto::int64_vals_size() const {
  return _internal_int64_vals_size();
}
inline void ExampleProto::clear_int64_vals() {
  int64_vals_.Clear();
}
inline int64_t ExampleProto::_internal_int64_vals(int index) const {
  return int64_vals_.Get(index);
}
inline int64_t ExampleProto::int64_vals(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.int64_vals)
  return _internal_int64_vals(index);
}
inline void ExampleProto::set_int64_vals(int index, int64_t value) {
  int64_vals_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.int64_vals)
}
inline void ExampleProto::_internal_add_int64_vals(int64_t value) {
  int64_vals_.Add(value);
}
inline void ExampleProto::add_int64_vals(int64_t value) {
  _internal_add_int64_vals(value);
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.int64_vals)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
ExampleProto::_internal_int64_vals() const {
  return int64_vals_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
ExampleProto::int64_vals() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.int64_vals)
  return _internal_int64_vals();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
ExampleProto::_internal_mutable_int64_vals() {
  return &int64_vals_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
ExampleProto::mutable_int64_vals() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.int64_vals)
  return _internal_mutable_int64_vals();
}

// repeated double double_vals = 11;
inline int ExampleProto::_internal_double_vals_size() const {
  return double_vals_.size();
}
inline int ExampleProto::double_vals_size() const {
  return _internal_double_vals_size();
}
inline void ExampleProto::clear_double_vals() {
  double_vals_.Clear();
}
inline double ExampleProto::_internal_double_vals(int index) const {
  return double_vals_.Get(index);
}
inline double ExampleProto::double_vals(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.double_vals)
  return _internal_double_vals(index);
}
inline void ExampleProto::set_double_vals(int index, double value) {
  double_vals_.Set(index, value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.double_vals)
}
inline void ExampleProto::_internal_add_double_vals(double value) {
  double_vals_.Add(value);
}
inline void ExampleProto::add_double_vals(double value) {
  _internal_add_double_vals(value);
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.double_vals)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
ExampleProto::_internal_double_vals() const {
  return double_vals_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
ExampleProto::double_vals() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.double_vals)
  return _internal_double_vals();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
ExampleProto::_internal_mutable_double_vals() {
  return &double_vals_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
ExampleProto::mutable_double_vals() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.double_vals)
  return _internal_mutable_double_vals();
}

// repeated string string_vals = 12;
inline int ExampleProto::_internal_string_vals_size() const {
  return string_vals_.size();
}
inline int ExampleProto::string_vals_size() const {
  return _internal_string_vals_size();
}
inline void ExampleProto::clear_string_vals() {
  string_vals_.Clear();
}
inline std::string* ExampleProto::add_string_vals() {
  std::string* _s = _internal_add_string_vals();
  // @@protoc_insertion_point(field_add_mutable:ProtobufBlueprintSp.ExampleProto.string_vals)
  return _s;
}
inline const std::string& ExampleProto::_internal_string_vals(int index) const {
  return string_vals_.Get(index);
}
inline const std::string& ExampleProto::string_vals(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.string_vals)
  return _internal_string_vals(index);
}
inline std::string* ExampleProto::mutable_string_vals(int index) {
  // @@protoc_insertion_point(field_mutable:ProtobufBlueprintSp.ExampleProto.string_vals)
  return string_vals_.Mutable(index);
}
inline void ExampleProto::set_string_vals(int index, const std::string& value) {
  string_vals_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::set_string_vals(int index, std::string&& value) {
  string_vals_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::set_string_vals(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  string_vals_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::set_string_vals(int index, const char* value, size_t size) {
  string_vals_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline std::string* ExampleProto::_internal_add_string_vals() {
  return string_vals_.Add();
}
inline void ExampleProto::add_string_vals(const std::string& value) {
  string_vals_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::add_string_vals(std::string&& value) {
  string_vals_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::add_string_vals(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  string_vals_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline void ExampleProto::add_string_vals(const char* value, size_t size) {
  string_vals_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:ProtobufBlueprintSp.ExampleProto.string_vals)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
ExampleProto::string_vals() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.string_vals)
  return string_vals_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
ExampleProto::mutable_string_vals() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.string_vals)
  return &string_vals_;
}

// repeated .ProtobufBlueprintSp.ExampleSubProto sub_protos = 13;
inline int ExampleProto::_internal_sub_protos_size() const {
  return sub_protos_.size();
}
inline int ExampleProto::sub_protos_size() const {
  return _internal_sub_protos_size();
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::mutable_sub_protos(int index) {
  // @@protoc_insertion_point(field_mutable:ProtobufBlueprintSp.ExampleProto.sub_protos)
  return sub_protos_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtobufBlueprintSp::ExampleSubProto >*
ExampleProto::mutable_sub_protos() {
  // @@protoc_insertion_point(field_mutable_list:ProtobufBlueprintSp.ExampleProto.sub_protos)
  return &sub_protos_;
}
inline const ::ProtobufBlueprintSp::ExampleSubProto& ExampleProto::_internal_sub_protos(int index) const {
  return sub_protos_.Get(index);
}
inline const ::ProtobufBlueprintSp::ExampleSubProto& ExampleProto::sub_protos(int index) const {
  // @@protoc_insertion_point(field_get:ProtobufBlueprintSp.ExampleProto.sub_protos)
  return _internal_sub_protos(index);
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::_internal_add_sub_protos() {
  return sub_protos_.Add();
}
inline ::ProtobufBlueprintSp::ExampleSubProto* ExampleProto::add_sub_protos() {
  ::ProtobufBlueprintSp::ExampleSubProto* _add = _internal_add_sub_protos();
  // @@protoc_insertion_point(field_add:ProtobufBlueprintSp.ExampleProto.sub_protos)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtobufBlueprintSp::ExampleSubProto >&
ExampleProto::sub_protos() const {
  // @@protoc_insertion_point(field_list:ProtobufBlueprintSp.ExampleProto.sub_protos)
  return sub_protos_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace ProtobufBlueprintSp

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ExampleProto_2eproto