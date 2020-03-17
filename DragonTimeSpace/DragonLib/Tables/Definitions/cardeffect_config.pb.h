// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cardeffect_config.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cardeffect_5fconfig_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cardeffect_5fconfig_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_cardeffect_5fconfig_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cardeffect_5fconfig_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cardeffect_5fconfig_2eproto;
namespace pb {
class cardeffect_config;
class cardeffect_configDefaultTypeInternal;
extern cardeffect_configDefaultTypeInternal _cardeffect_config_default_instance_;
class cardeffect_config_t_cardeffect_config;
class cardeffect_config_t_cardeffect_configDefaultTypeInternal;
extern cardeffect_config_t_cardeffect_configDefaultTypeInternal _cardeffect_config_t_cardeffect_config_default_instance_;
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> ::pb::cardeffect_config* Arena::CreateMaybeMessage<::pb::cardeffect_config>(Arena*);
template<> ::pb::cardeffect_config_t_cardeffect_config* Arena::CreateMaybeMessage<::pb::cardeffect_config_t_cardeffect_config>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pb {

// ===================================================================

class cardeffect_config_t_cardeffect_config :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.cardeffect_config.t_cardeffect_config) */ {
 public:
  cardeffect_config_t_cardeffect_config();
  virtual ~cardeffect_config_t_cardeffect_config();

  cardeffect_config_t_cardeffect_config(const cardeffect_config_t_cardeffect_config& from);
  cardeffect_config_t_cardeffect_config(cardeffect_config_t_cardeffect_config&& from) noexcept
    : cardeffect_config_t_cardeffect_config() {
    *this = ::std::move(from);
  }

  inline cardeffect_config_t_cardeffect_config& operator=(const cardeffect_config_t_cardeffect_config& from) {
    CopyFrom(from);
    return *this;
  }
  inline cardeffect_config_t_cardeffect_config& operator=(cardeffect_config_t_cardeffect_config&& from) noexcept {
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
  static const cardeffect_config_t_cardeffect_config& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const cardeffect_config_t_cardeffect_config* internal_default_instance() {
    return reinterpret_cast<const cardeffect_config_t_cardeffect_config*>(
               &_cardeffect_config_t_cardeffect_config_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(cardeffect_config_t_cardeffect_config& a, cardeffect_config_t_cardeffect_config& b) {
    a.Swap(&b);
  }
  inline void Swap(cardeffect_config_t_cardeffect_config* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline cardeffect_config_t_cardeffect_config* New() const final {
    return CreateMaybeMessage<cardeffect_config_t_cardeffect_config>(nullptr);
  }

  cardeffect_config_t_cardeffect_config* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<cardeffect_config_t_cardeffect_config>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const cardeffect_config_t_cardeffect_config& from);
  void MergeFrom(const cardeffect_config_t_cardeffect_config& from);
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
  void InternalSwap(cardeffect_config_t_cardeffect_config* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.cardeffect_config.t_cardeffect_config";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cardeffect_5fconfig_2eproto);
    return ::descriptor_table_cardeffect_5fconfig_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCardeffectdesFieldNumber = 3,
    kProtypeFieldNumber = 6,
    kTbxidFieldNumber = 1,
    kIdFieldNumber = 2,
    kCardeffecttypeFieldNumber = 4,
    kEffecttypevalueFieldNumber = 5,
    kProvalueLowFieldNumber = 7,
    kProvalueHighFieldNumber = 8,
  };
  // required string cardeffectdes = 3;
  bool has_cardeffectdes() const;
  private:
  bool _internal_has_cardeffectdes() const;
  public:
  void clear_cardeffectdes();
  const std::string& cardeffectdes() const;
  void set_cardeffectdes(const std::string& value);
  void set_cardeffectdes(std::string&& value);
  void set_cardeffectdes(const char* value);
  void set_cardeffectdes(const char* value, size_t size);
  std::string* mutable_cardeffectdes();
  std::string* release_cardeffectdes();
  void set_allocated_cardeffectdes(std::string* cardeffectdes);
  private:
  const std::string& _internal_cardeffectdes() const;
  void _internal_set_cardeffectdes(const std::string& value);
  std::string* _internal_mutable_cardeffectdes();
  public:

  // required string protype = 6;
  bool has_protype() const;
  private:
  bool _internal_has_protype() const;
  public:
  void clear_protype();
  const std::string& protype() const;
  void set_protype(const std::string& value);
  void set_protype(std::string&& value);
  void set_protype(const char* value);
  void set_protype(const char* value, size_t size);
  std::string* mutable_protype();
  std::string* release_protype();
  void set_allocated_protype(std::string* protype);
  private:
  const std::string& _internal_protype() const;
  void _internal_set_protype(const std::string& value);
  std::string* _internal_mutable_protype();
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

  // required uint32 cardeffecttype = 4;
  bool has_cardeffecttype() const;
  private:
  bool _internal_has_cardeffecttype() const;
  public:
  void clear_cardeffecttype();
  ::PROTOBUF_NAMESPACE_ID::uint32 cardeffecttype() const;
  void set_cardeffecttype(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_cardeffecttype() const;
  void _internal_set_cardeffecttype(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 effecttypevalue = 5;
  bool has_effecttypevalue() const;
  private:
  bool _internal_has_effecttypevalue() const;
  public:
  void clear_effecttypevalue();
  ::PROTOBUF_NAMESPACE_ID::uint32 effecttypevalue() const;
  void set_effecttypevalue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_effecttypevalue() const;
  void _internal_set_effecttypevalue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 provalue_low = 7;
  bool has_provalue_low() const;
  private:
  bool _internal_has_provalue_low() const;
  public:
  void clear_provalue_low();
  ::PROTOBUF_NAMESPACE_ID::uint32 provalue_low() const;
  void set_provalue_low(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_provalue_low() const;
  void _internal_set_provalue_low(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 provalue_high = 8;
  bool has_provalue_high() const;
  private:
  bool _internal_has_provalue_high() const;
  public:
  void clear_provalue_high();
  ::PROTOBUF_NAMESPACE_ID::uint32 provalue_high() const;
  void set_provalue_high(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_provalue_high() const;
  void _internal_set_provalue_high(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:pb.cardeffect_config.t_cardeffect_config)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr cardeffectdes_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr protype_;
  ::PROTOBUF_NAMESPACE_ID::uint32 tbxid_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  ::PROTOBUF_NAMESPACE_ID::uint32 cardeffecttype_;
  ::PROTOBUF_NAMESPACE_ID::uint32 effecttypevalue_;
  ::PROTOBUF_NAMESPACE_ID::uint32 provalue_low_;
  ::PROTOBUF_NAMESPACE_ID::uint32 provalue_high_;
  friend struct ::TableStruct_cardeffect_5fconfig_2eproto;
};
// -------------------------------------------------------------------

class cardeffect_config :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.cardeffect_config) */ {
 public:
  cardeffect_config();
  virtual ~cardeffect_config();

  cardeffect_config(const cardeffect_config& from);
  cardeffect_config(cardeffect_config&& from) noexcept
    : cardeffect_config() {
    *this = ::std::move(from);
  }

  inline cardeffect_config& operator=(const cardeffect_config& from) {
    CopyFrom(from);
    return *this;
  }
  inline cardeffect_config& operator=(cardeffect_config&& from) noexcept {
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
  static const cardeffect_config& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const cardeffect_config* internal_default_instance() {
    return reinterpret_cast<const cardeffect_config*>(
               &_cardeffect_config_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(cardeffect_config& a, cardeffect_config& b) {
    a.Swap(&b);
  }
  inline void Swap(cardeffect_config* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline cardeffect_config* New() const final {
    return CreateMaybeMessage<cardeffect_config>(nullptr);
  }

  cardeffect_config* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<cardeffect_config>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const cardeffect_config& from);
  void MergeFrom(const cardeffect_config& from);
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
  void InternalSwap(cardeffect_config* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.cardeffect_config";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cardeffect_5fconfig_2eproto);
    return ::descriptor_table_cardeffect_5fconfig_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef cardeffect_config_t_cardeffect_config t_cardeffect_config;

  // accessors -------------------------------------------------------

  enum : int {
    kDatasFieldNumber = 1,
  };
  // repeated .pb.cardeffect_config.t_cardeffect_config datas = 1;
  int datas_size() const;
  private:
  int _internal_datas_size() const;
  public:
  void clear_datas();
  ::pb::cardeffect_config_t_cardeffect_config* mutable_datas(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::cardeffect_config_t_cardeffect_config >*
      mutable_datas();
  private:
  const ::pb::cardeffect_config_t_cardeffect_config& _internal_datas(int index) const;
  ::pb::cardeffect_config_t_cardeffect_config* _internal_add_datas();
  public:
  const ::pb::cardeffect_config_t_cardeffect_config& datas(int index) const;
  ::pb::cardeffect_config_t_cardeffect_config* add_datas();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::cardeffect_config_t_cardeffect_config >&
      datas() const;

  // @@protoc_insertion_point(class_scope:pb.cardeffect_config)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::cardeffect_config_t_cardeffect_config > datas_;
  friend struct ::TableStruct_cardeffect_5fconfig_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// cardeffect_config_t_cardeffect_config

// required uint32 tbxid = 1 [default = 0];
inline bool cardeffect_config_t_cardeffect_config::_internal_has_tbxid() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_tbxid() const {
  return _internal_has_tbxid();
}
inline void cardeffect_config_t_cardeffect_config::clear_tbxid() {
  tbxid_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_tbxid() const {
  return tbxid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::tbxid() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.tbxid)
  return _internal_tbxid();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  tbxid_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_tbxid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_tbxid(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.tbxid)
}

// required uint32 id = 2 [default = 0];
inline bool cardeffect_config_t_cardeffect_config::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_id() const {
  return _internal_has_id();
}
inline void cardeffect_config_t_cardeffect_config::clear_id() {
  id_ = 0u;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::id() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.id)
  return _internal_id();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000008u;
  id_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.id)
}

// required string cardeffectdes = 3;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_cardeffectdes() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_cardeffectdes() const {
  return _internal_has_cardeffectdes();
}
inline void cardeffect_config_t_cardeffect_config::clear_cardeffectdes() {
  cardeffectdes_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& cardeffect_config_t_cardeffect_config::cardeffectdes() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
  return _internal_cardeffectdes();
}
inline void cardeffect_config_t_cardeffect_config::set_cardeffectdes(const std::string& value) {
  _internal_set_cardeffectdes(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
}
inline std::string* cardeffect_config_t_cardeffect_config::mutable_cardeffectdes() {
  // @@protoc_insertion_point(field_mutable:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
  return _internal_mutable_cardeffectdes();
}
inline const std::string& cardeffect_config_t_cardeffect_config::_internal_cardeffectdes() const {
  return cardeffectdes_.GetNoArena();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_cardeffectdes(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  cardeffectdes_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void cardeffect_config_t_cardeffect_config::set_cardeffectdes(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  cardeffectdes_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
}
inline void cardeffect_config_t_cardeffect_config::set_cardeffectdes(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  cardeffectdes_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
}
inline void cardeffect_config_t_cardeffect_config::set_cardeffectdes(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  cardeffectdes_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
}
inline std::string* cardeffect_config_t_cardeffect_config::_internal_mutable_cardeffectdes() {
  _has_bits_[0] |= 0x00000001u;
  return cardeffectdes_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* cardeffect_config_t_cardeffect_config::release_cardeffectdes() {
  // @@protoc_insertion_point(field_release:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
  if (!_internal_has_cardeffectdes()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return cardeffectdes_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void cardeffect_config_t_cardeffect_config::set_allocated_cardeffectdes(std::string* cardeffectdes) {
  if (cardeffectdes != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  cardeffectdes_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), cardeffectdes);
  // @@protoc_insertion_point(field_set_allocated:pb.cardeffect_config.t_cardeffect_config.cardeffectdes)
}

// required uint32 cardeffecttype = 4;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_cardeffecttype() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_cardeffecttype() const {
  return _internal_has_cardeffecttype();
}
inline void cardeffect_config_t_cardeffect_config::clear_cardeffecttype() {
  cardeffecttype_ = 0u;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_cardeffecttype() const {
  return cardeffecttype_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::cardeffecttype() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.cardeffecttype)
  return _internal_cardeffecttype();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_cardeffecttype(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000010u;
  cardeffecttype_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_cardeffecttype(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_cardeffecttype(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.cardeffecttype)
}

// required uint32 effecttypevalue = 5;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_effecttypevalue() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_effecttypevalue() const {
  return _internal_has_effecttypevalue();
}
inline void cardeffect_config_t_cardeffect_config::clear_effecttypevalue() {
  effecttypevalue_ = 0u;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_effecttypevalue() const {
  return effecttypevalue_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::effecttypevalue() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.effecttypevalue)
  return _internal_effecttypevalue();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_effecttypevalue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000020u;
  effecttypevalue_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_effecttypevalue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_effecttypevalue(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.effecttypevalue)
}

// required string protype = 6;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_protype() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_protype() const {
  return _internal_has_protype();
}
inline void cardeffect_config_t_cardeffect_config::clear_protype() {
  protype_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& cardeffect_config_t_cardeffect_config::protype() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.protype)
  return _internal_protype();
}
inline void cardeffect_config_t_cardeffect_config::set_protype(const std::string& value) {
  _internal_set_protype(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.protype)
}
inline std::string* cardeffect_config_t_cardeffect_config::mutable_protype() {
  // @@protoc_insertion_point(field_mutable:pb.cardeffect_config.t_cardeffect_config.protype)
  return _internal_mutable_protype();
}
inline const std::string& cardeffect_config_t_cardeffect_config::_internal_protype() const {
  return protype_.GetNoArena();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_protype(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  protype_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void cardeffect_config_t_cardeffect_config::set_protype(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  protype_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.cardeffect_config.t_cardeffect_config.protype)
}
inline void cardeffect_config_t_cardeffect_config::set_protype(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  protype_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.cardeffect_config.t_cardeffect_config.protype)
}
inline void cardeffect_config_t_cardeffect_config::set_protype(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  protype_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.cardeffect_config.t_cardeffect_config.protype)
}
inline std::string* cardeffect_config_t_cardeffect_config::_internal_mutable_protype() {
  _has_bits_[0] |= 0x00000002u;
  return protype_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* cardeffect_config_t_cardeffect_config::release_protype() {
  // @@protoc_insertion_point(field_release:pb.cardeffect_config.t_cardeffect_config.protype)
  if (!_internal_has_protype()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return protype_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void cardeffect_config_t_cardeffect_config::set_allocated_protype(std::string* protype) {
  if (protype != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  protype_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), protype);
  // @@protoc_insertion_point(field_set_allocated:pb.cardeffect_config.t_cardeffect_config.protype)
}

// required uint32 provalue_low = 7;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_provalue_low() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_provalue_low() const {
  return _internal_has_provalue_low();
}
inline void cardeffect_config_t_cardeffect_config::clear_provalue_low() {
  provalue_low_ = 0u;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_provalue_low() const {
  return provalue_low_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::provalue_low() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.provalue_low)
  return _internal_provalue_low();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_provalue_low(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000040u;
  provalue_low_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_provalue_low(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_provalue_low(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.provalue_low)
}

// required uint32 provalue_high = 8;
inline bool cardeffect_config_t_cardeffect_config::_internal_has_provalue_high() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool cardeffect_config_t_cardeffect_config::has_provalue_high() const {
  return _internal_has_provalue_high();
}
inline void cardeffect_config_t_cardeffect_config::clear_provalue_high() {
  provalue_high_ = 0u;
  _has_bits_[0] &= ~0x00000080u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::_internal_provalue_high() const {
  return provalue_high_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 cardeffect_config_t_cardeffect_config::provalue_high() const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.t_cardeffect_config.provalue_high)
  return _internal_provalue_high();
}
inline void cardeffect_config_t_cardeffect_config::_internal_set_provalue_high(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000080u;
  provalue_high_ = value;
}
inline void cardeffect_config_t_cardeffect_config::set_provalue_high(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_provalue_high(value);
  // @@protoc_insertion_point(field_set:pb.cardeffect_config.t_cardeffect_config.provalue_high)
}

// -------------------------------------------------------------------

// cardeffect_config

// repeated .pb.cardeffect_config.t_cardeffect_config datas = 1;
inline int cardeffect_config::_internal_datas_size() const {
  return datas_.size();
}
inline int cardeffect_config::datas_size() const {
  return _internal_datas_size();
}
inline void cardeffect_config::clear_datas() {
  datas_.Clear();
}
inline ::pb::cardeffect_config_t_cardeffect_config* cardeffect_config::mutable_datas(int index) {
  // @@protoc_insertion_point(field_mutable:pb.cardeffect_config.datas)
  return datas_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::cardeffect_config_t_cardeffect_config >*
cardeffect_config::mutable_datas() {
  // @@protoc_insertion_point(field_mutable_list:pb.cardeffect_config.datas)
  return &datas_;
}
inline const ::pb::cardeffect_config_t_cardeffect_config& cardeffect_config::_internal_datas(int index) const {
  return datas_.Get(index);
}
inline const ::pb::cardeffect_config_t_cardeffect_config& cardeffect_config::datas(int index) const {
  // @@protoc_insertion_point(field_get:pb.cardeffect_config.datas)
  return _internal_datas(index);
}
inline ::pb::cardeffect_config_t_cardeffect_config* cardeffect_config::_internal_add_datas() {
  return datas_.Add();
}
inline ::pb::cardeffect_config_t_cardeffect_config* cardeffect_config::add_datas() {
  // @@protoc_insertion_point(field_add:pb.cardeffect_config.datas)
  return _internal_add_datas();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::pb::cardeffect_config_t_cardeffect_config >&
cardeffect_config::datas() const {
  // @@protoc_insertion_point(field_list:pb.cardeffect_config.datas)
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
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cardeffect_5fconfig_2eproto
