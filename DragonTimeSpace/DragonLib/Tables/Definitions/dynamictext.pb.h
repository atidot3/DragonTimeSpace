// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dynamictext.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_dynamictext_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_dynamictext_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_dynamictext_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_dynamictext_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_dynamictext_2eproto;
namespace pb {
class dynamictext;
class dynamictextDefaultTypeInternal;
extern dynamictextDefaultTypeInternal _dynamictext_default_instance_;
class dynamictext_t_dynamic_text_config;
class dynamictext_t_dynamic_text_configDefaultTypeInternal;
extern dynamictext_t_dynamic_text_configDefaultTypeInternal _dynamictext_t_dynamic_text_config_default_instance_;
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> ::pb::dynamictext* Arena::CreateMaybeMessage<::pb::dynamictext>(Arena*);
template<> ::pb::dynamictext_t_dynamic_text_config* Arena::CreateMaybeMessage<::pb::dynamictext_t_dynamic_text_config>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pb {

// ===================================================================

class dynamictext_t_dynamic_text_config :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.dynamictext.t_dynamic_text_config) */ {
 public:
  dynamictext_t_dynamic_text_config();
  virtual ~dynamictext_t_dynamic_text_config();

  dynamictext_t_dynamic_text_config(const dynamictext_t_dynamic_text_config& from);
  dynamictext_t_dynamic_text_config(dynamictext_t_dynamic_text_config&& from) noexcept
    : dynamictext_t_dynamic_text_config() {
    *this = ::std::move(from);
  }

  inline dynamictext_t_dynamic_text_config& operator=(const dynamictext_t_dynamic_text_config& from) {
    CopyFrom(from);
    return *this;
  }
  inline dynamictext_t_dynamic_text_config& operator=(dynamictext_t_dynamic_text_config&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const dynamictext_t_dynamic_text_config& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const dynamictext_t_dynamic_text_config* internal_default_instance() {
    return reinterpret_cast<const dynamictext_t_dynamic_text_config*>(
               &_dynamictext_t_dynamic_text_config_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(dynamictext_t_dynamic_text_config& a, dynamictext_t_dynamic_text_config& b) {
    a.Swap(&b);
  }
  inline void Swap(dynamictext_t_dynamic_text_config* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline dynamictext_t_dynamic_text_config* New() const final {
    return CreateMaybeMessage<dynamictext_t_dynamic_text_config>(nullptr);
  }

  dynamictext_t_dynamic_text_config* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<dynamictext_t_dynamic_text_config>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const dynamictext_t_dynamic_text_config& from);
  void MergeFrom(const dynamictext_t_dynamic_text_config& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(dynamictext_t_dynamic_text_config* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.dynamictext.t_dynamic_text_config";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_dynamictext_2eproto);
    return ::descriptor_table_dynamictext_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kContentFieldNumber = 3,
    kTbxidFieldNumber = 1,
    kIdFieldNumber = 2,
  };
  // required string content = 3;
  bool has_content() const;
  private:
  bool _internal_has_content() const;
  public:
  void clear_content();
  const std::string& content() const;
  void set_content(const std::string& value);
  void set_content(std::string&& value);
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  std::string* mutable_content();
  std::string* release_content();
  void set_allocated_content(std::string* content);
  private:
  const std::string& _internal_content() const;
  void _internal_set_content(const std::string& value);
  std::string* _internal_mutable_content();
  public:

  // required uint32 tbxid = 1 [default = 0];
  bool has_tbxid() const;
  private:
  bool _internal_has_tbxid() const;
  public:
  void clear_tbxid();
  ::PROTOBUF_NAMESPACE_ID::uint32 tbxid() const;
  void set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_tbxid() const;
  void _internal_set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 id = 2 [default = 0];
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:pb.dynamictext.t_dynamic_text_config)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr content_;
  ::PROTOBUF_NAMESPACE_ID::uint32 tbxid_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  friend struct ::TableStruct_dynamictext_2eproto;
};
// -------------------------------------------------------------------

class dynamictext :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.dynamictext) */ {
 public:
  dynamictext();
  virtual ~dynamictext();

  dynamictext(const dynamictext& from);
  dynamictext(dynamictext&& from) noexcept
    : dynamictext() {
    *this = ::std::move(from);
  }

  inline dynamictext& operator=(const dynamictext& from) {
    CopyFrom(from);
    return *this;
  }
  inline dynamictext& operator=(dynamictext&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const dynamictext& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const dynamictext* internal_default_instance() {
    return reinterpret_cast<const dynamictext*>(
               &_dynamictext_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(dynamictext& a, dynamictext& b) {
    a.Swap(&b);
  }
  inline void Swap(dynamictext* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline dynamictext* New() const final {
    return CreateMaybeMessage<dynamictext>(nullptr);
  }

  dynamictext* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<dynamictext>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const dynamictext& from);
  void MergeFrom(const dynamictext& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(dynamictext* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.dynamictext";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_dynamictext_2eproto);
    return ::descriptor_table_dynamictext_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef dynamictext_t_dynamic_text_config t_dynamic_text_config;

  // accessors -------------------------------------------------------

  enum : int {
    kDatasFieldNumber = 1,
  };
  // repeated .pb.dynamictext.t_dynamic_text_config datas = 1;
  int datas_size() const;
  private:
  int _internal_datas_size() const;
  public:
  void clear_datas();
  ::pb::dynamictext_t_dynamic_text_config* mutable_datas(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::dynamictext_t_dynamic_text_config >*
      mutable_datas();
  private:
  const ::pb::dynamictext_t_dynamic_text_config& _internal_datas(int index) const;
  ::pb::dynamictext_t_dynamic_text_config* _internal_add_datas();
  public:
  const ::pb::dynamictext_t_dynamic_text_config& datas(int index) const;
  ::pb::dynamictext_t_dynamic_text_config* add_datas();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::dynamictext_t_dynamic_text_config >&
      datas() const;

  // @@protoc_insertion_point(class_scope:pb.dynamictext)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::dynamictext_t_dynamic_text_config > datas_;
  friend struct ::TableStruct_dynamictext_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// dynamictext_t_dynamic_text_config

// required uint32 tbxid = 1 [default = 0];
inline bool dynamictext_t_dynamic_text_config::_internal_has_tbxid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool dynamictext_t_dynamic_text_config::has_tbxid() const {
  return _internal_has_tbxid();
}
inline void dynamictext_t_dynamic_text_config::clear_tbxid() {
  tbxid_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 dynamictext_t_dynamic_text_config::_internal_tbxid() const {
  return tbxid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 dynamictext_t_dynamic_text_config::tbxid() const {
  // @@protoc_insertion_point(field_get:pb.dynamictext.t_dynamic_text_config.tbxid)
  return _internal_tbxid();
}
inline void dynamictext_t_dynamic_text_config::_internal_set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  tbxid_ = value;
}
inline void dynamictext_t_dynamic_text_config::set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_tbxid(value);
  // @@protoc_insertion_point(field_set:pb.dynamictext.t_dynamic_text_config.tbxid)
}

// required uint32 id = 2 [default = 0];
inline bool dynamictext_t_dynamic_text_config::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool dynamictext_t_dynamic_text_config::has_id() const {
  return _internal_has_id();
}
inline void dynamictext_t_dynamic_text_config::clear_id() {
  id_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 dynamictext_t_dynamic_text_config::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 dynamictext_t_dynamic_text_config::id() const {
  // @@protoc_insertion_point(field_get:pb.dynamictext.t_dynamic_text_config.id)
  return _internal_id();
}
inline void dynamictext_t_dynamic_text_config::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  id_ = value;
}
inline void dynamictext_t_dynamic_text_config::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:pb.dynamictext.t_dynamic_text_config.id)
}

// required string content = 3;
inline bool dynamictext_t_dynamic_text_config::_internal_has_content() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool dynamictext_t_dynamic_text_config::has_content() const {
  return _internal_has_content();
}
inline void dynamictext_t_dynamic_text_config::clear_content() {
  content_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& dynamictext_t_dynamic_text_config::content() const {
  // @@protoc_insertion_point(field_get:pb.dynamictext.t_dynamic_text_config.content)
  return _internal_content();
}
inline void dynamictext_t_dynamic_text_config::set_content(const std::string& value) {
  _internal_set_content(value);
  // @@protoc_insertion_point(field_set:pb.dynamictext.t_dynamic_text_config.content)
}
inline std::string* dynamictext_t_dynamic_text_config::mutable_content() {
  // @@protoc_insertion_point(field_mutable:pb.dynamictext.t_dynamic_text_config.content)
  return _internal_mutable_content();
}
inline const std::string& dynamictext_t_dynamic_text_config::_internal_content() const {
  return content_.GetNoArena();
}
inline void dynamictext_t_dynamic_text_config::_internal_set_content(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  content_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void dynamictext_t_dynamic_text_config::set_content(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  content_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.dynamictext.t_dynamic_text_config.content)
}
inline void dynamictext_t_dynamic_text_config::set_content(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  content_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.dynamictext.t_dynamic_text_config.content)
}
inline void dynamictext_t_dynamic_text_config::set_content(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  content_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.dynamictext.t_dynamic_text_config.content)
}
inline std::string* dynamictext_t_dynamic_text_config::_internal_mutable_content() {
  _has_bits_[0] |= 0x00000001u;
  return content_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* dynamictext_t_dynamic_text_config::release_content() {
  // @@protoc_insertion_point(field_release:pb.dynamictext.t_dynamic_text_config.content)
  if (!_internal_has_content()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return content_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void dynamictext_t_dynamic_text_config::set_allocated_content(std::string* content) {
  if (content != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  content_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:pb.dynamictext.t_dynamic_text_config.content)
}

// -------------------------------------------------------------------

// dynamictext

// repeated .pb.dynamictext.t_dynamic_text_config datas = 1;
inline int dynamictext::_internal_datas_size() const {
  return datas_.size();
}
inline int dynamictext::datas_size() const {
  return _internal_datas_size();
}
inline void dynamictext::clear_datas() {
  datas_.Clear();
}
inline ::pb::dynamictext_t_dynamic_text_config* dynamictext::mutable_datas(int index) {
  // @@protoc_insertion_point(field_mutable:pb.dynamictext.datas)
  return datas_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::dynamictext_t_dynamic_text_config >*
dynamictext::mutable_datas() {
  // @@protoc_insertion_point(field_mutable_list:pb.dynamictext.datas)
  return &datas_;
}
inline const ::pb::dynamictext_t_dynamic_text_config& dynamictext::_internal_datas(int index) const {
  return datas_.Get(index);
}
inline const ::pb::dynamictext_t_dynamic_text_config& dynamictext::datas(int index) const {
  // @@protoc_insertion_point(field_get:pb.dynamictext.datas)
  return _internal_datas(index);
}
inline ::pb::dynamictext_t_dynamic_text_config* dynamictext::_internal_add_datas() {
  return datas_.Add();
}
inline ::pb::dynamictext_t_dynamic_text_config* dynamictext::add_datas() {
  // @@protoc_insertion_point(field_add:pb.dynamictext.datas)
  return _internal_add_datas();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::dynamictext_t_dynamic_text_config >&
dynamictext::datas() const {
  // @@protoc_insertion_point(field_list:pb.dynamictext.datas)
  return datas_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_dynamictext_2eproto
