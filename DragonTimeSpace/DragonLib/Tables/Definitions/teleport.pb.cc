// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: teleport.proto

#include "teleport.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_teleport_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_teleport_t_teleport_teleport_2eproto;
namespace pb {
class teleport_t_teleportDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<teleport_t_teleport> _instance;
} _teleport_t_teleport_default_instance_;
class teleportDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<teleport> _instance;
} _teleport_default_instance_;
}  // namespace pb
static void InitDefaultsscc_info_teleport_teleport_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_teleport_default_instance_;
    new (ptr) ::pb::teleport();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::teleport::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_teleport_teleport_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_teleport_teleport_2eproto}, {
      &scc_info_teleport_t_teleport_teleport_2eproto.base,}};

static void InitDefaultsscc_info_teleport_t_teleport_teleport_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_teleport_t_teleport_default_instance_;
    new (ptr) ::pb::teleport_t_teleport();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::teleport_t_teleport::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_teleport_t_teleport_teleport_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_teleport_t_teleport_teleport_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_teleport_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_teleport_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_teleport_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_teleport_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, tbxid_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, id_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, npcid_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, desc_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, mapid_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, coordinate_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport_t_teleport, cost_),
  3,
  4,
  5,
  0,
  6,
  1,
  2,
  PROTOBUF_FIELD_OFFSET(::pb::teleport, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::teleport, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::teleport, datas_),
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 12, sizeof(::pb::teleport_t_teleport)},
  { 19, 25, sizeof(::pb::teleport)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_teleport_t_teleport_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_teleport_default_instance_),
};

const char descriptor_table_protodef_teleport_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016teleport.proto\022\002pb\"\257\001\n\010teleport\022&\n\005dat"
  "as\030\001 \003(\0132\027.pb.teleport.t_teleport\032{\n\nt_t"
  "eleport\022\020\n\005tbxid\030\001 \002(\r:\0010\022\r\n\002id\030\002 \002(\r:\0010"
  "\022\r\n\005npcid\030\003 \002(\r\022\014\n\004Desc\030\004 \002(\t\022\r\n\005mapid\030\005"
  " \002(\r\022\022\n\ncoordinate\030\006 \002(\t\022\014\n\004cost\030\007 \002(\t"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_teleport_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_teleport_2eproto_sccs[2] = {
  &scc_info_teleport_teleport_2eproto.base,
  &scc_info_teleport_t_teleport_teleport_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_teleport_2eproto_once;
static bool descriptor_table_teleport_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_teleport_2eproto = {
  &descriptor_table_teleport_2eproto_initialized, descriptor_table_protodef_teleport_2eproto, "teleport.proto", 198,
  &descriptor_table_teleport_2eproto_once, descriptor_table_teleport_2eproto_sccs, descriptor_table_teleport_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_teleport_2eproto::offsets,
  file_level_metadata_teleport_2eproto, 2, file_level_enum_descriptors_teleport_2eproto, file_level_service_descriptors_teleport_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_teleport_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_teleport_2eproto)), true);
namespace pb {

// ===================================================================

void teleport_t_teleport::InitAsDefaultInstance() {
}
class teleport_t_teleport::_Internal {
 public:
  using HasBits = decltype(std::declval<teleport_t_teleport>()._has_bits_);
  static void set_has_tbxid(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_npcid(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_desc(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_mapid(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_coordinate(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_cost(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

teleport_t_teleport::teleport_t_teleport()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.teleport.t_teleport)
}
teleport_t_teleport::teleport_t_teleport(const teleport_t_teleport& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  desc_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_desc()) {
    desc_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.desc_);
  }
  coordinate_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_coordinate()) {
    coordinate_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.coordinate_);
  }
  cost_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_cost()) {
    cost_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cost_);
  }
  ::memcpy(&tbxid_, &from.tbxid_,
    static_cast<size_t>(reinterpret_cast<char*>(&mapid_) -
    reinterpret_cast<char*>(&tbxid_)) + sizeof(mapid_));
  // @@protoc_insertion_point(copy_constructor:pb.teleport.t_teleport)
}

void teleport_t_teleport::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_teleport_t_teleport_teleport_2eproto.base);
  desc_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  coordinate_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  cost_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&tbxid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&mapid_) -
      reinterpret_cast<char*>(&tbxid_)) + sizeof(mapid_));
}

teleport_t_teleport::~teleport_t_teleport() {
  // @@protoc_insertion_point(destructor:pb.teleport.t_teleport)
  SharedDtor();
}

void teleport_t_teleport::SharedDtor() {
  desc_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  coordinate_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  cost_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void teleport_t_teleport::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const teleport_t_teleport& teleport_t_teleport::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_teleport_t_teleport_teleport_2eproto.base);
  return *internal_default_instance();
}


void teleport_t_teleport::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.teleport.t_teleport)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      desc_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      coordinate_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      cost_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x00000078u) {
    ::memset(&tbxid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&mapid_) -
        reinterpret_cast<char*>(&tbxid_)) + sizeof(mapid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* teleport_t_teleport::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // required uint32 id = 2 [default = 0];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 npcid = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_npcid(&has_bits);
          npcid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string Desc = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_desc();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.teleport.t_teleport.Desc");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 mapid = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_mapid(&has_bits);
          mapid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string coordinate = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          auto str = _internal_mutable_coordinate();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.teleport.t_teleport.coordinate");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string cost = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          auto str = _internal_mutable_cost();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.teleport.t_teleport.cost");
          #endif  // !NDEBUG
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

::PROTOBUF_NAMESPACE_ID::uint8* teleport_t_teleport::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.teleport.t_teleport)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 tbxid = 1 [default = 0];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_tbxid(), target);
  }

  // required uint32 id = 2 [default = 0];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_id(), target);
  }

  // required uint32 npcid = 3;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_npcid(), target);
  }

  // required string Desc = 4;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_desc().data(), static_cast<int>(this->_internal_desc().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.teleport.t_teleport.Desc");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_desc(), target);
  }

  // required uint32 mapid = 5;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(5, this->_internal_mapid(), target);
  }

  // required string coordinate = 6;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_coordinate().data(), static_cast<int>(this->_internal_coordinate().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.teleport.t_teleport.coordinate");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_coordinate(), target);
  }

  // required string cost = 7;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_cost().data(), static_cast<int>(this->_internal_cost().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.teleport.t_teleport.cost");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_cost(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.teleport.t_teleport)
  return target;
}

size_t teleport_t_teleport::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:pb.teleport.t_teleport)
  size_t total_size = 0;

  if (_internal_has_desc()) {
    // required string Desc = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_desc());
  }

  if (_internal_has_coordinate()) {
    // required string coordinate = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_coordinate());
  }

  if (_internal_has_cost()) {
    // required string cost = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cost());
  }

  if (_internal_has_tbxid()) {
    // required uint32 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tbxid());
  }

  if (_internal_has_id()) {
    // required uint32 id = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  if (_internal_has_npcid()) {
    // required uint32 npcid = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_npcid());
  }

  if (_internal_has_mapid()) {
    // required uint32 mapid = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_mapid());
  }

  return total_size;
}
size_t teleport_t_teleport::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.teleport.t_teleport)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000007f) ^ 0x0000007f) == 0) {  // All required fields are present.
    // required string Desc = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_desc());

    // required string coordinate = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_coordinate());

    // required string cost = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cost());

    // required uint32 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tbxid());

    // required uint32 id = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());

    // required uint32 npcid = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_npcid());

    // required uint32 mapid = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_mapid());

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

void teleport_t_teleport::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.teleport.t_teleport)
  GOOGLE_DCHECK_NE(&from, this);
  const teleport_t_teleport* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<teleport_t_teleport>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.teleport.t_teleport)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.teleport.t_teleport)
    MergeFrom(*source);
  }
}

void teleport_t_teleport::MergeFrom(const teleport_t_teleport& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.teleport.t_teleport)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      desc_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.desc_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      coordinate_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.coordinate_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      cost_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cost_);
    }
    if (cached_has_bits & 0x00000008u) {
      tbxid_ = from.tbxid_;
    }
    if (cached_has_bits & 0x00000010u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000020u) {
      npcid_ = from.npcid_;
    }
    if (cached_has_bits & 0x00000040u) {
      mapid_ = from.mapid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void teleport_t_teleport::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.teleport.t_teleport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void teleport_t_teleport::CopyFrom(const teleport_t_teleport& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.teleport.t_teleport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool teleport_t_teleport::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000007f) != 0x0000007f) return false;
  return true;
}

void teleport_t_teleport::InternalSwap(teleport_t_teleport* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  desc_.Swap(&other->desc_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  coordinate_.Swap(&other->coordinate_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  cost_.Swap(&other->cost_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(tbxid_, other->tbxid_);
  swap(id_, other->id_);
  swap(npcid_, other->npcid_);
  swap(mapid_, other->mapid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata teleport_t_teleport::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void teleport::InitAsDefaultInstance() {
}
class teleport::_Internal {
 public:
  using HasBits = decltype(std::declval<teleport>()._has_bits_);
};

teleport::teleport()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.teleport)
}
teleport::teleport(const teleport& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      datas_(from.datas_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:pb.teleport)
}

void teleport::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_teleport_teleport_2eproto.base);
}

teleport::~teleport() {
  // @@protoc_insertion_point(destructor:pb.teleport)
  SharedDtor();
}

void teleport::SharedDtor() {
}

void teleport::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const teleport& teleport::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_teleport_teleport_2eproto.base);
  return *internal_default_instance();
}


void teleport::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.teleport)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  datas_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* teleport::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .pb.teleport.t_teleport datas = 1;
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

::PROTOBUF_NAMESPACE_ID::uint8* teleport::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.teleport)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .pb.teleport.t_teleport datas = 1;
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
  // @@protoc_insertion_point(serialize_to_array_end:pb.teleport)
  return target;
}

size_t teleport::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.teleport)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .pb.teleport.t_teleport datas = 1;
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

void teleport::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.teleport)
  GOOGLE_DCHECK_NE(&from, this);
  const teleport* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<teleport>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.teleport)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.teleport)
    MergeFrom(*source);
  }
}

void teleport::MergeFrom(const teleport& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.teleport)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  datas_.MergeFrom(from.datas_);
}

void teleport::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.teleport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void teleport::CopyFrom(const teleport& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.teleport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool teleport::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(datas_)) return false;
  return true;
}

void teleport::InternalSwap(teleport* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  datas_.InternalSwap(&other->datas_);
}

::PROTOBUF_NAMESPACE_ID::Metadata teleport::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::teleport_t_teleport* Arena::CreateMaybeMessage< ::pb::teleport_t_teleport >(Arena* arena) {
  return Arena::CreateInternal< ::pb::teleport_t_teleport >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::teleport* Arena::CreateMaybeMessage< ::pb::teleport >(Arena* arena) {
  return Arena::CreateInternal< ::pb::teleport >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
