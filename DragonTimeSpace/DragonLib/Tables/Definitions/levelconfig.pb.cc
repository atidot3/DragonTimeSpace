// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: levelconfig.proto

#include "levelconfig.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_levelconfig_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_levelconfig_t_level_config_levelconfig_2eproto;
namespace pb {
class levelconfig_t_level_configDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<levelconfig_t_level_config> _instance;
} _levelconfig_t_level_config_default_instance_;
class levelconfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<levelconfig> _instance;
} _levelconfig_default_instance_;
}  // namespace pb
static void InitDefaultsscc_info_levelconfig_levelconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_levelconfig_default_instance_;
    new (ptr) ::pb::levelconfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::levelconfig::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_levelconfig_levelconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_levelconfig_levelconfig_2eproto}, {
      &scc_info_levelconfig_t_level_config_levelconfig_2eproto.base,}};

static void InitDefaultsscc_info_levelconfig_t_level_config_levelconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_levelconfig_t_level_config_default_instance_;
    new (ptr) ::pb::levelconfig_t_level_config();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::levelconfig_t_level_config::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_levelconfig_t_level_config_levelconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_levelconfig_t_level_config_levelconfig_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_levelconfig_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_levelconfig_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_levelconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_levelconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, tbxid_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, level_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, levelupexp_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, del_protect_time_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, unlockskill_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_levelup_exp_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_levelup_salary_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_daily_rewards_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_daily_leader_rewards_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_daily_maintain_fund_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig_t_level_config, guild_member_limit_),
  3,
  4,
  5,
  6,
  0,
  7,
  8,
  1,
  2,
  9,
  10,
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::levelconfig, datas_),
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 16, sizeof(::pb::levelconfig_t_level_config)},
  { 27, 33, sizeof(::pb::levelconfig)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_levelconfig_t_level_config_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_levelconfig_default_instance_),
};

const char descriptor_table_protodef_levelconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021levelconfig.proto\022\002pb\"\357\002\n\013levelconfig\022"
  "-\n\005datas\030\001 \003(\0132\036.pb.levelconfig.t_level_"
  "config\032\260\002\n\016t_level_config\022\020\n\005tbxid\030\001 \002(\r"
  ":\0010\022\020\n\005level\030\002 \002(\r:\0010\022\022\n\nlevelupexp\030\003 \002("
  "\r\022\030\n\020del_protect_time\030\004 \002(\r\022\023\n\013unlockski"
  "ll\030\005 \002(\t\022\031\n\021guild_levelup_exp\030\006 \002(\r\022\034\n\024g"
  "uild_levelup_salary\030\007 \002(\r\022\033\n\023guild_daily"
  "_rewards\030\010 \002(\t\022\"\n\032guild_daily_leader_rew"
  "ards\030\t \002(\t\022!\n\031guild_daily_maintain_fund\030"
  "\n \002(\r\022\032\n\022guild_member_limit\030\013 \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_levelconfig_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_levelconfig_2eproto_sccs[2] = {
  &scc_info_levelconfig_levelconfig_2eproto.base,
  &scc_info_levelconfig_t_level_config_levelconfig_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_levelconfig_2eproto_once;
static bool descriptor_table_levelconfig_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_levelconfig_2eproto = {
  &descriptor_table_levelconfig_2eproto_initialized, descriptor_table_protodef_levelconfig_2eproto, "levelconfig.proto", 393,
  &descriptor_table_levelconfig_2eproto_once, descriptor_table_levelconfig_2eproto_sccs, descriptor_table_levelconfig_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_levelconfig_2eproto::offsets,
  file_level_metadata_levelconfig_2eproto, 2, file_level_enum_descriptors_levelconfig_2eproto, file_level_service_descriptors_levelconfig_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_levelconfig_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_levelconfig_2eproto)), true);
namespace pb {

// ===================================================================

void levelconfig_t_level_config::InitAsDefaultInstance() {
}
class levelconfig_t_level_config::_Internal {
 public:
  using HasBits = decltype(std::declval<levelconfig_t_level_config>()._has_bits_);
  static void set_has_tbxid(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_level(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_levelupexp(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_del_protect_time(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_unlockskill(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_guild_levelup_exp(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_guild_levelup_salary(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_guild_daily_rewards(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_guild_daily_leader_rewards(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_guild_daily_maintain_fund(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static void set_has_guild_member_limit(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
};

levelconfig_t_level_config::levelconfig_t_level_config()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.levelconfig.t_level_config)
}
levelconfig_t_level_config::levelconfig_t_level_config(const levelconfig_t_level_config& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  unlockskill_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_unlockskill()) {
    unlockskill_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.unlockskill_);
  }
  guild_daily_rewards_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_guild_daily_rewards()) {
    guild_daily_rewards_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guild_daily_rewards_);
  }
  guild_daily_leader_rewards_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_guild_daily_leader_rewards()) {
    guild_daily_leader_rewards_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guild_daily_leader_rewards_);
  }
  ::memcpy(&tbxid_, &from.tbxid_,
    static_cast<size_t>(reinterpret_cast<char*>(&guild_member_limit_) -
    reinterpret_cast<char*>(&tbxid_)) + sizeof(guild_member_limit_));
  // @@protoc_insertion_point(copy_constructor:pb.levelconfig.t_level_config)
}

void levelconfig_t_level_config::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_levelconfig_t_level_config_levelconfig_2eproto.base);
  unlockskill_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  guild_daily_rewards_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  guild_daily_leader_rewards_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&tbxid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&guild_member_limit_) -
      reinterpret_cast<char*>(&tbxid_)) + sizeof(guild_member_limit_));
}

levelconfig_t_level_config::~levelconfig_t_level_config() {
  // @@protoc_insertion_point(destructor:pb.levelconfig.t_level_config)
  SharedDtor();
}

void levelconfig_t_level_config::SharedDtor() {
  unlockskill_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  guild_daily_rewards_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  guild_daily_leader_rewards_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void levelconfig_t_level_config::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const levelconfig_t_level_config& levelconfig_t_level_config::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_levelconfig_t_level_config_levelconfig_2eproto.base);
  return *internal_default_instance();
}


void levelconfig_t_level_config::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.levelconfig.t_level_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      unlockskill_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      guild_daily_rewards_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      guild_daily_leader_rewards_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x000000f8u) {
    ::memset(&tbxid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&guild_levelup_exp_) -
        reinterpret_cast<char*>(&tbxid_)) + sizeof(guild_levelup_exp_));
  }
  if (cached_has_bits & 0x00000700u) {
    ::memset(&guild_levelup_salary_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&guild_member_limit_) -
        reinterpret_cast<char*>(&guild_levelup_salary_)) + sizeof(guild_member_limit_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* levelconfig_t_level_config::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 tbxid = 1 [default = 0];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_tbxid(&has_bits);
          tbxid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 level = 2 [default = 0];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_level(&has_bits);
          level_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 levelupexp = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_levelupexp(&has_bits);
          levelupexp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 del_protect_time = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_del_protect_time(&has_bits);
          del_protect_time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string unlockskill = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_unlockskill();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.levelconfig.t_level_config.unlockskill");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 guild_levelup_exp = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_guild_levelup_exp(&has_bits);
          guild_levelup_exp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 guild_levelup_salary = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_guild_levelup_salary(&has_bits);
          guild_levelup_salary_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string guild_daily_rewards = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          auto str = _internal_mutable_guild_daily_rewards();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.levelconfig.t_level_config.guild_daily_rewards");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string guild_daily_leader_rewards = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          auto str = _internal_mutable_guild_daily_leader_rewards();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.levelconfig.t_level_config.guild_daily_leader_rewards");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 guild_daily_maintain_fund = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          _Internal::set_has_guild_daily_maintain_fund(&has_bits);
          guild_daily_maintain_fund_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 guild_member_limit = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 88)) {
          _Internal::set_has_guild_member_limit(&has_bits);
          guild_member_limit_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* levelconfig_t_level_config::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.levelconfig.t_level_config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 tbxid = 1 [default = 0];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_tbxid(), target);
  }

  // required uint32 level = 2 [default = 0];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_level(), target);
  }

  // required uint32 levelupexp = 3;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_levelupexp(), target);
  }

  // required uint32 del_protect_time = 4;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_del_protect_time(), target);
  }

  // required string unlockskill = 5;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_unlockskill().data(), static_cast<int>(this->_internal_unlockskill().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.levelconfig.t_level_config.unlockskill");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_unlockskill(), target);
  }

  // required uint32 guild_levelup_exp = 6;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(6, this->_internal_guild_levelup_exp(), target);
  }

  // required uint32 guild_levelup_salary = 7;
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(7, this->_internal_guild_levelup_salary(), target);
  }

  // required string guild_daily_rewards = 8;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_guild_daily_rewards().data(), static_cast<int>(this->_internal_guild_daily_rewards().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.levelconfig.t_level_config.guild_daily_rewards");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_guild_daily_rewards(), target);
  }

  // required string guild_daily_leader_rewards = 9;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_guild_daily_leader_rewards().data(), static_cast<int>(this->_internal_guild_daily_leader_rewards().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.levelconfig.t_level_config.guild_daily_leader_rewards");
    target = stream->WriteStringMaybeAliased(
        9, this->_internal_guild_daily_leader_rewards(), target);
  }

  // required uint32 guild_daily_maintain_fund = 10;
  if (cached_has_bits & 0x00000200u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(10, this->_internal_guild_daily_maintain_fund(), target);
  }

  // required uint32 guild_member_limit = 11;
  if (cached_has_bits & 0x00000400u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(11, this->_internal_guild_member_limit(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.levelconfig.t_level_config)
  return target;
}

size_t levelconfig_t_level_config::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:pb.levelconfig.t_level_config)
  size_t total_size = 0;

  if (_internal_has_unlockskill()) {
    // required string unlockskill = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_unlockskill());
  }

  if (_internal_has_guild_daily_rewards()) {
    // required string guild_daily_rewards = 8;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_guild_daily_rewards());
  }

  if (_internal_has_guild_daily_leader_rewards()) {
    // required string guild_daily_leader_rewards = 9;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_guild_daily_leader_rewards());
  }

  if (_internal_has_tbxid()) {
    // required uint32 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tbxid());
  }

  if (_internal_has_level()) {
    // required uint32 level = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_level());
  }

  if (_internal_has_levelupexp()) {
    // required uint32 levelupexp = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_levelupexp());
  }

  if (_internal_has_del_protect_time()) {
    // required uint32 del_protect_time = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_del_protect_time());
  }

  if (_internal_has_guild_levelup_exp()) {
    // required uint32 guild_levelup_exp = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_levelup_exp());
  }

  if (_internal_has_guild_levelup_salary()) {
    // required uint32 guild_levelup_salary = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_levelup_salary());
  }

  if (_internal_has_guild_daily_maintain_fund()) {
    // required uint32 guild_daily_maintain_fund = 10;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_daily_maintain_fund());
  }

  if (_internal_has_guild_member_limit()) {
    // required uint32 guild_member_limit = 11;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_member_limit());
  }

  return total_size;
}
size_t levelconfig_t_level_config::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.levelconfig.t_level_config)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x000007ff) ^ 0x000007ff) == 0) {  // All required fields are present.
    // required string unlockskill = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_unlockskill());

    // required string guild_daily_rewards = 8;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_guild_daily_rewards());

    // required string guild_daily_leader_rewards = 9;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_guild_daily_leader_rewards());

    // required uint32 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tbxid());

    // required uint32 level = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_level());

    // required uint32 levelupexp = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_levelupexp());

    // required uint32 del_protect_time = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_del_protect_time());

    // required uint32 guild_levelup_exp = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_levelup_exp());

    // required uint32 guild_levelup_salary = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_levelup_salary());

    // required uint32 guild_daily_maintain_fund = 10;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_daily_maintain_fund());

    // required uint32 guild_member_limit = 11;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_guild_member_limit());

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

void levelconfig_t_level_config::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.levelconfig.t_level_config)
  GOOGLE_DCHECK_NE(&from, this);
  const levelconfig_t_level_config* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<levelconfig_t_level_config>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.levelconfig.t_level_config)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.levelconfig.t_level_config)
    MergeFrom(*source);
  }
}

void levelconfig_t_level_config::MergeFrom(const levelconfig_t_level_config& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.levelconfig.t_level_config)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      unlockskill_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.unlockskill_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      guild_daily_rewards_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guild_daily_rewards_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      guild_daily_leader_rewards_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guild_daily_leader_rewards_);
    }
    if (cached_has_bits & 0x00000008u) {
      tbxid_ = from.tbxid_;
    }
    if (cached_has_bits & 0x00000010u) {
      level_ = from.level_;
    }
    if (cached_has_bits & 0x00000020u) {
      levelupexp_ = from.levelupexp_;
    }
    if (cached_has_bits & 0x00000040u) {
      del_protect_time_ = from.del_protect_time_;
    }
    if (cached_has_bits & 0x00000080u) {
      guild_levelup_exp_ = from.guild_levelup_exp_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00000700u) {
    if (cached_has_bits & 0x00000100u) {
      guild_levelup_salary_ = from.guild_levelup_salary_;
    }
    if (cached_has_bits & 0x00000200u) {
      guild_daily_maintain_fund_ = from.guild_daily_maintain_fund_;
    }
    if (cached_has_bits & 0x00000400u) {
      guild_member_limit_ = from.guild_member_limit_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void levelconfig_t_level_config::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.levelconfig.t_level_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void levelconfig_t_level_config::CopyFrom(const levelconfig_t_level_config& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.levelconfig.t_level_config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool levelconfig_t_level_config::IsInitialized() const {
  if ((_has_bits_[0] & 0x000007ff) != 0x000007ff) return false;
  return true;
}

void levelconfig_t_level_config::InternalSwap(levelconfig_t_level_config* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  unlockskill_.Swap(&other->unlockskill_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  guild_daily_rewards_.Swap(&other->guild_daily_rewards_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  guild_daily_leader_rewards_.Swap(&other->guild_daily_leader_rewards_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(tbxid_, other->tbxid_);
  swap(level_, other->level_);
  swap(levelupexp_, other->levelupexp_);
  swap(del_protect_time_, other->del_protect_time_);
  swap(guild_levelup_exp_, other->guild_levelup_exp_);
  swap(guild_levelup_salary_, other->guild_levelup_salary_);
  swap(guild_daily_maintain_fund_, other->guild_daily_maintain_fund_);
  swap(guild_member_limit_, other->guild_member_limit_);
}

::PROTOBUF_NAMESPACE_ID::Metadata levelconfig_t_level_config::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void levelconfig::InitAsDefaultInstance() {
}
class levelconfig::_Internal {
 public:
  using HasBits = decltype(std::declval<levelconfig>()._has_bits_);
};

levelconfig::levelconfig()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.levelconfig)
}
levelconfig::levelconfig(const levelconfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      datas_(from.datas_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:pb.levelconfig)
}

void levelconfig::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_levelconfig_levelconfig_2eproto.base);
}

levelconfig::~levelconfig() {
  // @@protoc_insertion_point(destructor:pb.levelconfig)
  SharedDtor();
}

void levelconfig::SharedDtor() {
}

void levelconfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const levelconfig& levelconfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_levelconfig_levelconfig_2eproto.base);
  return *internal_default_instance();
}


void levelconfig::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.levelconfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  datas_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* levelconfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .pb.levelconfig.t_level_config datas = 1;
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

::PROTOBUF_NAMESPACE_ID::uint8* levelconfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.levelconfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .pb.levelconfig.t_level_config datas = 1;
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
  // @@protoc_insertion_point(serialize_to_array_end:pb.levelconfig)
  return target;
}

size_t levelconfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.levelconfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .pb.levelconfig.t_level_config datas = 1;
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

void levelconfig::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.levelconfig)
  GOOGLE_DCHECK_NE(&from, this);
  const levelconfig* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<levelconfig>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.levelconfig)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.levelconfig)
    MergeFrom(*source);
  }
}

void levelconfig::MergeFrom(const levelconfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.levelconfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  datas_.MergeFrom(from.datas_);
}

void levelconfig::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.levelconfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void levelconfig::CopyFrom(const levelconfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.levelconfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool levelconfig::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(datas_)) return false;
  return true;
}

void levelconfig::InternalSwap(levelconfig* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  datas_.InternalSwap(&other->datas_);
}

::PROTOBUF_NAMESPACE_ID::Metadata levelconfig::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::levelconfig_t_level_config* Arena::CreateMaybeMessage< ::pb::levelconfig_t_level_config >(Arena* arena) {
  return Arena::CreateInternal< ::pb::levelconfig_t_level_config >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::levelconfig* Arena::CreateMaybeMessage< ::pb::levelconfig >(Arena* arena) {
  return Arena::CreateInternal< ::pb::levelconfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>