// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dnachip_config.proto

#include "dnachip_config.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_dnachip_5fconfig_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto;
namespace pb {
class dnachip_config_t_dnachip_configDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<dnachip_config_t_dnachip_config> _instance;
} _dnachip_config_t_dnachip_config_default_instance_;
class dnachip_configDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<dnachip_config> _instance;
} _dnachip_config_default_instance_;
}  // namespace pb
static void InitDefaultsscc_info_dnachip_config_dnachip_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_dnachip_config_default_instance_;
    new (ptr) ::pb::dnachip_config();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::dnachip_config::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_dnachip_config_dnachip_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_dnachip_config_dnachip_5fconfig_2eproto}, {
      &scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto.base,}};

static void InitDefaultsscc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_dnachip_config_t_dnachip_config_default_instance_;
    new (ptr) ::pb::dnachip_config_t_dnachip_config();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::dnachip_config_t_dnachip_config::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_dnachip_5fconfig_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_dnachip_5fconfig_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_dnachip_5fconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_dnachip_5fconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, tbxid_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, chipid_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, chipname_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, chipicon_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, chiptips_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, level_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, type_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, property_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config_t_dnachip_config, goldcost_),
  4,
  5,
  0,
  1,
  2,
  6,
  7,
  3,
  8,
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::dnachip_config, datas_),
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 14, sizeof(::pb::dnachip_config_t_dnachip_config)},
  { 23, 29, sizeof(::pb::dnachip_config)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_dnachip_config_t_dnachip_config_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_dnachip_config_default_instance_),
};

const char descriptor_table_protodef_dnachip_5fconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024dnachip_config.proto\022\002pb\"\365\001\n\016dnachip_c"
  "onfig\0222\n\005datas\030\001 \003(\0132#.pb.dnachip_config"
  ".t_dnachip_config\032\256\001\n\020t_dnachip_config\022\020"
  "\n\005tbxid\030\001 \002(\004:\0010\022\021\n\006chipid\030\002 \002(\004:\0010\022\020\n\010c"
  "hipname\030\003 \002(\t\022\020\n\010chipicon\030\004 \002(\t\022\020\n\010chipt"
  "ips\030\005 \002(\t\022\r\n\005level\030\006 \002(\r\022\014\n\004type\030\007 \002(\r\022\020"
  "\n\010property\030\010 \002(\t\022\020\n\010goldcost\030\t \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_dnachip_5fconfig_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_dnachip_5fconfig_2eproto_sccs[2] = {
  &scc_info_dnachip_config_dnachip_5fconfig_2eproto.base,
  &scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_dnachip_5fconfig_2eproto_once;
static bool descriptor_table_dnachip_5fconfig_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_dnachip_5fconfig_2eproto = {
  &descriptor_table_dnachip_5fconfig_2eproto_initialized, descriptor_table_protodef_dnachip_5fconfig_2eproto, "dnachip_config.proto", 274,
  &descriptor_table_dnachip_5fconfig_2eproto_once, descriptor_table_dnachip_5fconfig_2eproto_sccs, descriptor_table_dnachip_5fconfig_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_dnachip_5fconfig_2eproto::offsets,
  file_level_metadata_dnachip_5fconfig_2eproto, 2, file_level_enum_descriptors_dnachip_5fconfig_2eproto, file_level_service_descriptors_dnachip_5fconfig_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_dnachip_5fconfig_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_dnachip_5fconfig_2eproto)), true);
namespace pb {

// ===================================================================

void dnachip_config_t_dnachip_config::InitAsDefaultInstance() {
}
class dnachip_config_t_dnachip_config::_Internal {
 public:
  using HasBits = decltype(std::declval<dnachip_config_t_dnachip_config>()._has_bits_);
  static void set_has_tbxid(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_chipid(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_chipname(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_chipicon(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_chiptips(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_level(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_property(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_goldcost(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
};

dnachip_config_t_dnachip_config::dnachip_config_t_dnachip_config()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.dnachip_config.t_dnachip_config)
}
dnachip_config_t_dnachip_config::dnachip_config_t_dnachip_config(const dnachip_config_t_dnachip_config& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  chipname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_chipname()) {
    chipname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chipname_);
  }
  chipicon_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_chipicon()) {
    chipicon_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chipicon_);
  }
  chiptips_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_chiptips()) {
    chiptips_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chiptips_);
  }
  property_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_property()) {
    property_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.property_);
  }
  ::memcpy(&tbxid_, &from.tbxid_,
    static_cast<size_t>(reinterpret_cast<char*>(&goldcost_) -
    reinterpret_cast<char*>(&tbxid_)) + sizeof(goldcost_));
  // @@protoc_insertion_point(copy_constructor:pb.dnachip_config.t_dnachip_config)
}

void dnachip_config_t_dnachip_config::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto.base);
  chipname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chipicon_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chiptips_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  property_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&tbxid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&goldcost_) -
      reinterpret_cast<char*>(&tbxid_)) + sizeof(goldcost_));
}

dnachip_config_t_dnachip_config::~dnachip_config_t_dnachip_config() {
  // @@protoc_insertion_point(destructor:pb.dnachip_config.t_dnachip_config)
  SharedDtor();
}

void dnachip_config_t_dnachip_config::SharedDtor() {
  chipname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chipicon_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chiptips_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  property_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void dnachip_config_t_dnachip_config::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const dnachip_config_t_dnachip_config& dnachip_config_t_dnachip_config::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_dnachip_config_t_dnachip_config_dnachip_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void dnachip_config_t_dnachip_config::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.dnachip_config.t_dnachip_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      chipname_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      chipicon_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      chiptips_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000008u) {
      property_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x000000f0u) {
    ::memset(&tbxid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&type_) -
        reinterpret_cast<char*>(&tbxid_)) + sizeof(type_));
  }
  goldcost_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* dnachip_config_t_dnachip_config::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint64 tbxid = 1 [default = 0];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_tbxid(&has_bits);
          tbxid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint64 chipid = 2 [default = 0];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_chipid(&has_bits);
          chipid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string chipname = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_chipname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.dnachip_config.t_dnachip_config.chipname");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string chipicon = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_chipicon();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.dnachip_config.t_dnachip_config.chipicon");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string chiptips = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_chiptips();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.dnachip_config.t_dnachip_config.chiptips");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 level = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_level(&has_bits);
          level_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 type = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_type(&has_bits);
          type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string property = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          auto str = _internal_mutable_property();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.dnachip_config.t_dnachip_config.property");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 goldcost = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          _Internal::set_has_goldcost(&has_bits);
          goldcost_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* dnachip_config_t_dnachip_config::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.dnachip_config.t_dnachip_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint64 tbxid = 1 [default = 0];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_tbxid(), target);
  }

  // required uint64 chipid = 2 [default = 0];
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(2, this->_internal_chipid(), target);
  }

  // required string chipname = 3;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_chipname().data(), static_cast<int>(this->_internal_chipname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.dnachip_config.t_dnachip_config.chipname");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_chipname(), target);
  }

  // required string chipicon = 4;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_chipicon().data(), static_cast<int>(this->_internal_chipicon().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.dnachip_config.t_dnachip_config.chipicon");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_chipicon(), target);
  }

  // required string chiptips = 5;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_chiptips().data(), static_cast<int>(this->_internal_chiptips().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.dnachip_config.t_dnachip_config.chiptips");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_chiptips(), target);
  }

  // required uint32 level = 6;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(6, this->_internal_level(), target);
  }

  // required uint32 type = 7;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(7, this->_internal_type(), target);
  }

  // required string property = 8;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_property().data(), static_cast<int>(this->_internal_property().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.dnachip_config.t_dnachip_config.property");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_property(), target);
  }

  // required uint32 goldcost = 9;
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(9, this->_internal_goldcost(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.dnachip_config.t_dnachip_config)
  return target;
}

size_t dnachip_config_t_dnachip_config::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:pb.dnachip_config.t_dnachip_config)
  size_t total_size = 0;

  if (_internal_has_chipname()) {
    // required string chipname = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chipname());
  }

  if (_internal_has_chipicon()) {
    // required string chipicon = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chipicon());
  }

  if (_internal_has_chiptips()) {
    // required string chiptips = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chiptips());
  }

  if (_internal_has_property()) {
    // required string property = 8;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_property());
  }

  if (_internal_has_tbxid()) {
    // required uint64 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_tbxid());
  }

  if (_internal_has_chipid()) {
    // required uint64 chipid = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_chipid());
  }

  if (_internal_has_level()) {
    // required uint32 level = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_level());
  }

  if (_internal_has_type()) {
    // required uint32 type = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_type());
  }

  if (_internal_has_goldcost()) {
    // required uint32 goldcost = 9;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_goldcost());
  }

  return total_size;
}
size_t dnachip_config_t_dnachip_config::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.dnachip_config.t_dnachip_config)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x000001ff) ^ 0x000001ff) == 0) {  // All required fields are present.
    // required string chipname = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chipname());

    // required string chipicon = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chipicon());

    // required string chiptips = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chiptips());

    // required string property = 8;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_property());

    // required uint64 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_tbxid());

    // required uint64 chipid = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_chipid());

    // required uint32 level = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_level());

    // required uint32 type = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_type());

    // required uint32 goldcost = 9;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_goldcost());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void dnachip_config_t_dnachip_config::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.dnachip_config.t_dnachip_config)
  GOOGLE_DCHECK_NE(&from, this);
  const dnachip_config_t_dnachip_config* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<dnachip_config_t_dnachip_config>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.dnachip_config.t_dnachip_config)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.dnachip_config.t_dnachip_config)
    MergeFrom(*source);
  }
}

void dnachip_config_t_dnachip_config::MergeFrom(const dnachip_config_t_dnachip_config& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.dnachip_config.t_dnachip_config)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      chipname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chipname_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      chipicon_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chipicon_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      chiptips_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.chiptips_);
    }
    if (cached_has_bits & 0x00000008u) {
      _has_bits_[0] |= 0x00000008u;
      property_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.property_);
    }
    if (cached_has_bits & 0x00000010u) {
      tbxid_ = from.tbxid_;
    }
    if (cached_has_bits & 0x00000020u) {
      chipid_ = from.chipid_;
    }
    if (cached_has_bits & 0x00000040u) {
      level_ = from.level_;
    }
    if (cached_has_bits & 0x00000080u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00000100u) {
    _internal_set_goldcost(from._internal_goldcost());
  }
}

void dnachip_config_t_dnachip_config::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.dnachip_config.t_dnachip_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void dnachip_config_t_dnachip_config::CopyFrom(const dnachip_config_t_dnachip_config& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.dnachip_config.t_dnachip_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool dnachip_config_t_dnachip_config::IsInitialized() const {
  if ((_has_bits_[0] & 0x000001ff) != 0x000001ff) return false;
  return true;
}

void dnachip_config_t_dnachip_config::InternalSwap(dnachip_config_t_dnachip_config* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  chipname_.Swap(&other->chipname_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  chipicon_.Swap(&other->chipicon_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  chiptips_.Swap(&other->chiptips_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  property_.Swap(&other->property_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(tbxid_, other->tbxid_);
  swap(chipid_, other->chipid_);
  swap(level_, other->level_);
  swap(type_, other->type_);
  swap(goldcost_, other->goldcost_);
}

::PROTOBUF_NAMESPACE_ID::Metadata dnachip_config_t_dnachip_config::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void dnachip_config::InitAsDefaultInstance() {
}
class dnachip_config::_Internal {
 public:
  using HasBits = decltype(std::declval<dnachip_config>()._has_bits_);
};

dnachip_config::dnachip_config()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.dnachip_config)
}
dnachip_config::dnachip_config(const dnachip_config& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      datas_(from.datas_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:pb.dnachip_config)
}

void dnachip_config::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_dnachip_config_dnachip_5fconfig_2eproto.base);
}

dnachip_config::~dnachip_config() {
  // @@protoc_insertion_point(destructor:pb.dnachip_config)
  SharedDtor();
}

void dnachip_config::SharedDtor() {
}

void dnachip_config::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const dnachip_config& dnachip_config::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_dnachip_config_dnachip_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void dnachip_config::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.dnachip_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  datas_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* dnachip_config::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .pb.dnachip_config.t_dnachip_config datas = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_datas(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* dnachip_config::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.dnachip_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .pb.dnachip_config.t_dnachip_config datas = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_datas_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_datas(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.dnachip_config)
  return target;
}

size_t dnachip_config::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.dnachip_config)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .pb.dnachip_config.t_dnachip_config datas = 1;
  total_size += 1UL * this->_internal_datas_size();
  for (const auto& msg : this->datas_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void dnachip_config::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.dnachip_config)
  GOOGLE_DCHECK_NE(&from, this);
  const dnachip_config* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<dnachip_config>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.dnachip_config)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.dnachip_config)
    MergeFrom(*source);
  }
}

void dnachip_config::MergeFrom(const dnachip_config& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.dnachip_config)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  datas_.MergeFrom(from.datas_);
}

void dnachip_config::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.dnachip_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void dnachip_config::CopyFrom(const dnachip_config& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.dnachip_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool dnachip_config::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(datas_)) return false;
  return true;
}

void dnachip_config::InternalSwap(dnachip_config* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  datas_.InternalSwap(&other->datas_);
}

::PROTOBUF_NAMESPACE_ID::Metadata dnachip_config::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::dnachip_config_t_dnachip_config* Arena::CreateMaybeMessage< ::pb::dnachip_config_t_dnachip_config >(Arena* arena) {
  return Arena::CreateInternal< ::pb::dnachip_config_t_dnachip_config >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::dnachip_config* Arena::CreateMaybeMessage< ::pb::dnachip_config >(Arena* arena) {
  return Arena::CreateInternal< ::pb::dnachip_config >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
