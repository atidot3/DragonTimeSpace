// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cutscene.proto

#include "cutscene.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_cutscene_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_cutscene_t_cutscene_cutscene_2eproto;
namespace pb {
class cutscene_t_cutsceneDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<cutscene_t_cutscene> _instance;
} _cutscene_t_cutscene_default_instance_;
class cutsceneDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<cutscene> _instance;
} _cutscene_default_instance_;
}  // namespace pb
static void InitDefaultsscc_info_cutscene_cutscene_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_cutscene_default_instance_;
    new (ptr) ::pb::cutscene();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::cutscene::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_cutscene_cutscene_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_cutscene_cutscene_2eproto}, {
      &scc_info_cutscene_t_cutscene_cutscene_2eproto.base,}};

static void InitDefaultsscc_info_cutscene_t_cutscene_cutscene_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_cutscene_t_cutscene_default_instance_;
    new (ptr) ::pb::cutscene_t_cutscene();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::cutscene_t_cutscene::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_cutscene_t_cutscene_cutscene_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_cutscene_t_cutscene_cutscene_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cutscene_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cutscene_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cutscene_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cutscene_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, tbxid_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, id_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, name_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, desc_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, cutscene_key_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, show_type_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene_t_cutscene, mapip_),
  3,
  4,
  0,
  1,
  2,
  5,
  6,
  PROTOBUF_FIELD_OFFSET(::pb::cutscene, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::pb::cutscene, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::cutscene, datas_),
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 12, sizeof(::pb::cutscene_t_cutscene)},
  { 19, 25, sizeof(::pb::cutscene)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_cutscene_t_cutscene_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_cutscene_default_instance_),
};

const char descriptor_table_protodef_cutscene_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016cutscene.proto\022\002pb\"\266\001\n\010cutscene\022&\n\005dat"
  "as\030\001 \003(\0132\027.pb.cutscene.t_cutscene\032\201\001\n\nt_"
  "cutscene\022\020\n\005tbxid\030\001 \002(\r:\0010\022\r\n\002id\030\002 \002(\r:\001"
  "0\022\014\n\004name\030\003 \002(\t\022\014\n\004desc\030\004 \002(\t\022\024\n\014cutscen"
  "e_key\030\005 \002(\t\022\021\n\tshow_type\030\006 \002(\r\022\r\n\005mapip\030"
  "\007 \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cutscene_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cutscene_2eproto_sccs[2] = {
  &scc_info_cutscene_cutscene_2eproto.base,
  &scc_info_cutscene_t_cutscene_cutscene_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cutscene_2eproto_once;
static bool descriptor_table_cutscene_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cutscene_2eproto = {
  &descriptor_table_cutscene_2eproto_initialized, descriptor_table_protodef_cutscene_2eproto, "cutscene.proto", 205,
  &descriptor_table_cutscene_2eproto_once, descriptor_table_cutscene_2eproto_sccs, descriptor_table_cutscene_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_cutscene_2eproto::offsets,
  file_level_metadata_cutscene_2eproto, 2, file_level_enum_descriptors_cutscene_2eproto, file_level_service_descriptors_cutscene_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cutscene_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cutscene_2eproto)), true);
namespace pb {

// ===================================================================

void cutscene_t_cutscene::InitAsDefaultInstance() {
}
class cutscene_t_cutscene::_Internal {
 public:
  using HasBits = decltype(std::declval<cutscene_t_cutscene>()._has_bits_);
  static void set_has_tbxid(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_desc(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_cutscene_key(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_show_type(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_mapip(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
};

cutscene_t_cutscene::cutscene_t_cutscene()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.cutscene.t_cutscene)
}
cutscene_t_cutscene::cutscene_t_cutscene(const cutscene_t_cutscene& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_name()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  desc_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_desc()) {
    desc_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.desc_);
  }
  cutscene_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_cutscene_key()) {
    cutscene_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cutscene_key_);
  }
  ::memcpy(&tbxid_, &from.tbxid_,
    static_cast<size_t>(reinterpret_cast<char*>(&mapip_) -
    reinterpret_cast<char*>(&tbxid_)) + sizeof(mapip_));
  // @@protoc_insertion_point(copy_constructor:pb.cutscene.t_cutscene)
}

void cutscene_t_cutscene::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_cutscene_t_cutscene_cutscene_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  desc_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  cutscene_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&tbxid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&mapip_) -
      reinterpret_cast<char*>(&tbxid_)) + sizeof(mapip_));
}

cutscene_t_cutscene::~cutscene_t_cutscene() {
  // @@protoc_insertion_point(destructor:pb.cutscene.t_cutscene)
  SharedDtor();
}

void cutscene_t_cutscene::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  desc_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  cutscene_key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void cutscene_t_cutscene::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const cutscene_t_cutscene& cutscene_t_cutscene::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_cutscene_t_cutscene_cutscene_2eproto.base);
  return *internal_default_instance();
}


void cutscene_t_cutscene::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.cutscene.t_cutscene)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      desc_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      cutscene_key_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x00000078u) {
    ::memset(&tbxid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&mapip_) -
        reinterpret_cast<char*>(&tbxid_)) + sizeof(mapip_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* cutscene_t_cutscene::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // required string name = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.cutscene.t_cutscene.name");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string desc = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_desc();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.cutscene.t_cutscene.desc");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string cutscene_key = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_cutscene_key();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.cutscene.t_cutscene.cutscene_key");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 show_type = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_show_type(&has_bits);
          show_type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 mapip = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_mapip(&has_bits);
          mapip_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* cutscene_t_cutscene::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.cutscene.t_cutscene)
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

  // required string name = 3;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.cutscene.t_cutscene.name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_name(), target);
  }

  // required string desc = 4;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_desc().data(), static_cast<int>(this->_internal_desc().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.cutscene.t_cutscene.desc");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_desc(), target);
  }

  // required string cutscene_key = 5;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_cutscene_key().data(), static_cast<int>(this->_internal_cutscene_key().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "pb.cutscene.t_cutscene.cutscene_key");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_cutscene_key(), target);
  }

  // required uint32 show_type = 6;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(6, this->_internal_show_type(), target);
  }

  // required uint32 mapip = 7;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(7, this->_internal_mapip(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.cutscene.t_cutscene)
  return target;
}

size_t cutscene_t_cutscene::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:pb.cutscene.t_cutscene)
  size_t total_size = 0;

  if (_internal_has_name()) {
    // required string name = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  if (_internal_has_desc()) {
    // required string desc = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_desc());
  }

  if (_internal_has_cutscene_key()) {
    // required string cutscene_key = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cutscene_key());
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

  if (_internal_has_show_type()) {
    // required uint32 show_type = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_show_type());
  }

  if (_internal_has_mapip()) {
    // required uint32 mapip = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_mapip());
  }

  return total_size;
}
size_t cutscene_t_cutscene::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.cutscene.t_cutscene)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000007f) ^ 0x0000007f) == 0) {  // All required fields are present.
    // required string name = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());

    // required string desc = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_desc());

    // required string cutscene_key = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cutscene_key());

    // required uint32 tbxid = 1 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tbxid());

    // required uint32 id = 2 [default = 0];
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());

    // required uint32 show_type = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_show_type());

    // required uint32 mapip = 7;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_mapip());

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

void cutscene_t_cutscene::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.cutscene.t_cutscene)
  GOOGLE_DCHECK_NE(&from, this);
  const cutscene_t_cutscene* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<cutscene_t_cutscene>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.cutscene.t_cutscene)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.cutscene.t_cutscene)
    MergeFrom(*source);
  }
}

void cutscene_t_cutscene::MergeFrom(const cutscene_t_cutscene& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.cutscene.t_cutscene)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000007fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      desc_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.desc_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      cutscene_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cutscene_key_);
    }
    if (cached_has_bits & 0x00000008u) {
      tbxid_ = from.tbxid_;
    }
    if (cached_has_bits & 0x00000010u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000020u) {
      show_type_ = from.show_type_;
    }
    if (cached_has_bits & 0x00000040u) {
      mapip_ = from.mapip_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void cutscene_t_cutscene::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.cutscene.t_cutscene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void cutscene_t_cutscene::CopyFrom(const cutscene_t_cutscene& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.cutscene.t_cutscene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool cutscene_t_cutscene::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000007f) != 0x0000007f) return false;
  return true;
}

void cutscene_t_cutscene::InternalSwap(cutscene_t_cutscene* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  desc_.Swap(&other->desc_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  cutscene_key_.Swap(&other->cutscene_key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(tbxid_, other->tbxid_);
  swap(id_, other->id_);
  swap(show_type_, other->show_type_);
  swap(mapip_, other->mapip_);
}

::PROTOBUF_NAMESPACE_ID::Metadata cutscene_t_cutscene::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void cutscene::InitAsDefaultInstance() {
}
class cutscene::_Internal {
 public:
  using HasBits = decltype(std::declval<cutscene>()._has_bits_);
};

cutscene::cutscene()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.cutscene)
}
cutscene::cutscene(const cutscene& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      datas_(from.datas_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:pb.cutscene)
}

void cutscene::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_cutscene_cutscene_2eproto.base);
}

cutscene::~cutscene() {
  // @@protoc_insertion_point(destructor:pb.cutscene)
  SharedDtor();
}

void cutscene::SharedDtor() {
}

void cutscene::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const cutscene& cutscene::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_cutscene_cutscene_2eproto.base);
  return *internal_default_instance();
}


void cutscene::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.cutscene)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  datas_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* cutscene::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .pb.cutscene.t_cutscene datas = 1;
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

::PROTOBUF_NAMESPACE_ID::uint8* cutscene::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.cutscene)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .pb.cutscene.t_cutscene datas = 1;
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
  // @@protoc_insertion_point(serialize_to_array_end:pb.cutscene)
  return target;
}

size_t cutscene::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.cutscene)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .pb.cutscene.t_cutscene datas = 1;
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

void cutscene::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.cutscene)
  GOOGLE_DCHECK_NE(&from, this);
  const cutscene* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<cutscene>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.cutscene)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.cutscene)
    MergeFrom(*source);
  }
}

void cutscene::MergeFrom(const cutscene& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.cutscene)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  datas_.MergeFrom(from.datas_);
}

void cutscene::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.cutscene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void cutscene::CopyFrom(const cutscene& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.cutscene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool cutscene::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(datas_)) return false;
  return true;
}

void cutscene::InternalSwap(cutscene* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  datas_.InternalSwap(&other->datas_);
}

::PROTOBUF_NAMESPACE_ID::Metadata cutscene::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::cutscene_t_cutscene* Arena::CreateMaybeMessage< ::pb::cutscene_t_cutscene >(Arena* arena) {
  return Arena::CreateInternal< ::pb::cutscene_t_cutscene >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::cutscene* Arena::CreateMaybeMessage< ::pb::cutscene >(Arena* arena) {
  return Arena::CreateInternal< ::pb::cutscene >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
