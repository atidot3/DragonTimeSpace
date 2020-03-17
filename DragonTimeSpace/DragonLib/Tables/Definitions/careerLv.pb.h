// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: careerLv.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_careerLv_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_careerLv_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_careerLv_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_careerLv_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_careerLv_2eproto;
namespace pb {
class careerLv;
class careerLvDefaultTypeInternal;
extern careerLvDefaultTypeInternal _careerLv_default_instance_;
class careerLv_t_career_lv_config;
class careerLv_t_career_lv_configDefaultTypeInternal;
extern careerLv_t_career_lv_configDefaultTypeInternal _careerLv_t_career_lv_config_default_instance_;
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> ::pb::careerLv* Arena::CreateMaybeMessage<::pb::careerLv>(Arena*);
template<> ::pb::careerLv_t_career_lv_config* Arena::CreateMaybeMessage<::pb::careerLv_t_career_lv_config>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pb {

// ===================================================================

class careerLv_t_career_lv_config :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.careerLv.t_career_lv_config) */ {
 public:
  careerLv_t_career_lv_config();
  virtual ~careerLv_t_career_lv_config();

  careerLv_t_career_lv_config(const careerLv_t_career_lv_config& from);
  careerLv_t_career_lv_config(careerLv_t_career_lv_config&& from) noexcept
    : careerLv_t_career_lv_config() {
    *this = ::std::move(from);
  }

  inline careerLv_t_career_lv_config& operator=(const careerLv_t_career_lv_config& from) {
    CopyFrom(from);
    return *this;
  }
  inline careerLv_t_career_lv_config& operator=(careerLv_t_career_lv_config&& from) noexcept {
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
  static const careerLv_t_career_lv_config& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const careerLv_t_career_lv_config* internal_default_instance() {
    return reinterpret_cast<const careerLv_t_career_lv_config*>(
               &_careerLv_t_career_lv_config_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(careerLv_t_career_lv_config& a, careerLv_t_career_lv_config& b) {
    a.Swap(&b);
  }
  inline void Swap(careerLv_t_career_lv_config* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline careerLv_t_career_lv_config* New() const final {
    return CreateMaybeMessage<careerLv_t_career_lv_config>(nullptr);
  }

  careerLv_t_career_lv_config* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<careerLv_t_career_lv_config>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const careerLv_t_career_lv_config& from);
  void MergeFrom(const careerLv_t_career_lv_config& from);
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
  void InternalSwap(careerLv_t_career_lv_config* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.careerLv.t_career_lv_config";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_careerLv_2eproto);
    return ::descriptor_table_careerLv_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCareerbackFieldNumber = 4,
    kTbxidFieldNumber = 1,
    kLevelFieldNumber = 2,
    kProficiencyFieldNumber = 3,
  };
  // required string careerback = 4;
  bool has_careerback() const;
  private:
  bool _internal_has_careerback() const;
  public:
  void clear_careerback();
  const std::string& careerback() const;
  void set_careerback(const std::string& value);
  void set_careerback(std::string&& value);
  void set_careerback(const char* value);
  void set_careerback(const char* value, size_t size);
  std::string* mutable_careerback();
  std::string* release_careerback();
  void set_allocated_careerback(std::string* careerback);
  private:
  const std::string& _internal_careerback() const;
  void _internal_set_careerback(const std::string& value);
  std::string* _internal_mutable_careerback();
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

  // required uint32 level = 2 [default = 0];
  bool has_level() const;
  private:
  bool _internal_has_level() const;
  public:
  void clear_level();
  ::PROTOBUF_NAMESPACE_ID::uint32 level() const;
  void set_level(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_level() const;
  void _internal_set_level(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 proficiency = 3;
  bool has_proficiency() const;
  private:
  bool _internal_has_proficiency() const;
  public:
  void clear_proficiency();
  ::PROTOBUF_NAMESPACE_ID::uint32 proficiency() const;
  void set_proficiency(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_proficiency() const;
  void _internal_set_proficiency(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:pb.careerLv.t_career_lv_config)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr careerback_;
  ::PROTOBUF_NAMESPACE_ID::uint32 tbxid_;
  ::PROTOBUF_NAMESPACE_ID::uint32 level_;
  ::PROTOBUF_NAMESPACE_ID::uint32 proficiency_;
  friend struct ::TableStruct_careerLv_2eproto;
};
// -------------------------------------------------------------------

class careerLv :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.careerLv) */ {
 public:
  careerLv();
  virtual ~careerLv();

  careerLv(const careerLv& from);
  careerLv(careerLv&& from) noexcept
    : careerLv() {
    *this = ::std::move(from);
  }

  inline careerLv& operator=(const careerLv& from) {
    CopyFrom(from);
    return *this;
  }
  inline careerLv& operator=(careerLv&& from) noexcept {
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
  static const careerLv& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const careerLv* internal_default_instance() {
    return reinterpret_cast<const careerLv*>(
               &_careerLv_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(careerLv& a, careerLv& b) {
    a.Swap(&b);
  }
  inline void Swap(careerLv* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline careerLv* New() const final {
    return CreateMaybeMessage<careerLv>(nullptr);
  }

  careerLv* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<careerLv>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const careerLv& from);
  void MergeFrom(const careerLv& from);
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
  void InternalSwap(careerLv* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.careerLv";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_careerLv_2eproto);
    return ::descriptor_table_careerLv_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef careerLv_t_career_lv_config t_career_lv_config;

  // accessors -------------------------------------------------------

  enum : int {
    kDatasFieldNumber = 1,
  };
  // repeated .pb.careerLv.t_career_lv_config datas = 1;
  int datas_size() const;
  private:
  int _internal_datas_size() const;
  public:
  void clear_datas();
  ::pb::careerLv_t_career_lv_config* mutable_datas(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::careerLv_t_career_lv_config >*
      mutable_datas();
  private:
  const ::pb::careerLv_t_career_lv_config& _internal_datas(int index) const;
  ::pb::careerLv_t_career_lv_config* _internal_add_datas();
  public:
  const ::pb::careerLv_t_career_lv_config& datas(int index) const;
  ::pb::careerLv_t_career_lv_config* add_datas();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::careerLv_t_career_lv_config >&
      datas() const;

  // @@protoc_insertion_point(class_scope:pb.careerLv)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::careerLv_t_career_lv_config > datas_;
  friend struct ::TableStruct_careerLv_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// careerLv_t_career_lv_config

// required uint32 tbxid = 1 [default = 0];
inline bool careerLv_t_career_lv_config::_internal_has_tbxid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool careerLv_t_career_lv_config::has_tbxid() const {
  return _internal_has_tbxid();
}
inline void careerLv_t_career_lv_config::clear_tbxid() {
  tbxid_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::_internal_tbxid() const {
  return tbxid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::tbxid() const {
  // @@protoc_insertion_point(field_get:pb.careerLv.t_career_lv_config.tbxid)
  return _internal_tbxid();
}
inline void careerLv_t_career_lv_config::_internal_set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  tbxid_ = value;
}
inline void careerLv_t_career_lv_config::set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_tbxid(value);
  // @@protoc_insertion_point(field_set:pb.careerLv.t_career_lv_config.tbxid)
}

// required uint32 level = 2 [default = 0];
inline bool careerLv_t_career_lv_config::_internal_has_level() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool careerLv_t_career_lv_config::has_level() const {
  return _internal_has_level();
}
inline void careerLv_t_career_lv_config::clear_level() {
  level_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::_internal_level() const {
  return level_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::level() const {
  // @@protoc_insertion_point(field_get:pb.careerLv.t_career_lv_config.level)
  return _internal_level();
}
inline void careerLv_t_career_lv_config::_internal_set_level(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  level_ = value;
}
inline void careerLv_t_career_lv_config::set_level(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_level(value);
  // @@protoc_insertion_point(field_set:pb.careerLv.t_career_lv_config.level)
}

// required uint32 proficiency = 3;
inline bool careerLv_t_career_lv_config::_internal_has_proficiency() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool careerLv_t_career_lv_config::has_proficiency() const {
  return _internal_has_proficiency();
}
inline void careerLv_t_career_lv_config::clear_proficiency() {
  proficiency_ = 0u;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::_internal_proficiency() const {
  return proficiency_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 careerLv_t_career_lv_config::proficiency() const {
  // @@protoc_insertion_point(field_get:pb.careerLv.t_career_lv_config.proficiency)
  return _internal_proficiency();
}
inline void careerLv_t_career_lv_config::_internal_set_proficiency(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000008u;
  proficiency_ = value;
}
inline void careerLv_t_career_lv_config::set_proficiency(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_proficiency(value);
  // @@protoc_insertion_point(field_set:pb.careerLv.t_career_lv_config.proficiency)
}

// required string careerback = 4;
inline bool careerLv_t_career_lv_config::_internal_has_careerback() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool careerLv_t_career_lv_config::has_careerback() const {
  return _internal_has_careerback();
}
inline void careerLv_t_career_lv_config::clear_careerback() {
  careerback_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& careerLv_t_career_lv_config::careerback() const {
  // @@protoc_insertion_point(field_get:pb.careerLv.t_career_lv_config.careerback)
  return _internal_careerback();
}
inline void careerLv_t_career_lv_config::set_careerback(const std::string& value) {
  _internal_set_careerback(value);
  // @@protoc_insertion_point(field_set:pb.careerLv.t_career_lv_config.careerback)
}
inline std::string* careerLv_t_career_lv_config::mutable_careerback() {
  // @@protoc_insertion_point(field_mutable:pb.careerLv.t_career_lv_config.careerback)
  return _internal_mutable_careerback();
}
inline const std::string& careerLv_t_career_lv_config::_internal_careerback() const {
  return careerback_.GetNoArena();
}
inline void careerLv_t_career_lv_config::_internal_set_careerback(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  careerback_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void careerLv_t_career_lv_config::set_careerback(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  careerback_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.careerLv.t_career_lv_config.careerback)
}
inline void careerLv_t_career_lv_config::set_careerback(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  careerback_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.careerLv.t_career_lv_config.careerback)
}
inline void careerLv_t_career_lv_config::set_careerback(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  careerback_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.careerLv.t_career_lv_config.careerback)
}
inline std::string* careerLv_t_career_lv_config::_internal_mutable_careerback() {
  _has_bits_[0] |= 0x00000001u;
  return careerback_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* careerLv_t_career_lv_config::release_careerback() {
  // @@protoc_insertion_point(field_release:pb.careerLv.t_career_lv_config.careerback)
  if (!_internal_has_careerback()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return careerback_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void careerLv_t_career_lv_config::set_allocated_careerback(std::string* careerback) {
  if (careerback != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  careerback_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), careerback);
  // @@protoc_insertion_point(field_set_allocated:pb.careerLv.t_career_lv_config.careerback)
}

// -------------------------------------------------------------------

// careerLv

// repeated .pb.careerLv.t_career_lv_config datas = 1;
inline int careerLv::_internal_datas_size() const {
  return datas_.size();
}
inline int careerLv::datas_size() const {
  return _internal_datas_size();
}
inline void careerLv::clear_datas() {
  datas_.Clear();
}
inline ::pb::careerLv_t_career_lv_config* careerLv::mutable_datas(int index) {
  // @@protoc_insertion_point(field_mutable:pb.careerLv.datas)
  return datas_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::careerLv_t_career_lv_config >*
careerLv::mutable_datas() {
  // @@protoc_insertion_point(field_mutable_list:pb.careerLv.datas)
  return &datas_;
}
inline const ::pb::careerLv_t_career_lv_config& careerLv::_internal_datas(int index) const {
  return datas_.Get(index);
}
inline const ::pb::careerLv_t_career_lv_config& careerLv::datas(int index) const {
  // @@protoc_insertion_point(field_get:pb.careerLv.datas)
  return _internal_datas(index);
}
inline ::pb::careerLv_t_career_lv_config* careerLv::_internal_add_datas() {
  return datas_.Add();
}
inline ::pb::careerLv_t_career_lv_config* careerLv::add_datas() {
  // @@protoc_insertion_point(field_add:pb.careerLv.datas)
  return _internal_add_datas();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::careerLv_t_career_lv_config >&
careerLv::datas() const {
  // @@protoc_insertion_point(field_list:pb.careerLv.datas)
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
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_careerLv_2eproto