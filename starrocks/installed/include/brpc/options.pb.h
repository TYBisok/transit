// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: brpc/options.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_brpc_2foptions_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_brpc_2foptions_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_brpc_2foptions_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_brpc_2foptions_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_brpc_2foptions_2eproto;
namespace brpc {
class ChunkInfo;
class ChunkInfoDefaultTypeInternal;
extern ChunkInfoDefaultTypeInternal _ChunkInfo_default_instance_;
}  // namespace brpc
PROTOBUF_NAMESPACE_OPEN
template<> ::brpc::ChunkInfo* Arena::CreateMaybeMessage<::brpc::ChunkInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace brpc {

enum TalkType : int {
  TALK_TYPE_NORMAL = 0,
  TALK_TYPE_ONEWAY = 1
};
bool TalkType_IsValid(int value);
constexpr TalkType TalkType_MIN = TALK_TYPE_NORMAL;
constexpr TalkType TalkType_MAX = TALK_TYPE_ONEWAY;
constexpr int TalkType_ARRAYSIZE = TalkType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* TalkType_descriptor();
template<typename T>
inline const std::string& TalkType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, TalkType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function TalkType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    TalkType_descriptor(), enum_t_value);
}
inline bool TalkType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, TalkType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<TalkType>(
    TalkType_descriptor(), name, value);
}
enum ConnectionType : int {
  CONNECTION_TYPE_UNKNOWN = 0,
  CONNECTION_TYPE_SINGLE = 1,
  CONNECTION_TYPE_POOLED = 2,
  CONNECTION_TYPE_SHORT = 4
};
bool ConnectionType_IsValid(int value);
constexpr ConnectionType ConnectionType_MIN = CONNECTION_TYPE_UNKNOWN;
constexpr ConnectionType ConnectionType_MAX = CONNECTION_TYPE_SHORT;
constexpr int ConnectionType_ARRAYSIZE = ConnectionType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ConnectionType_descriptor();
template<typename T>
inline const std::string& ConnectionType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ConnectionType_descriptor(), enum_t_value);
}
inline bool ConnectionType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ConnectionType>(
    ConnectionType_descriptor(), name, value);
}
enum ProtocolType : int {
  PROTOCOL_UNKNOWN = 0,
  PROTOCOL_BAIDU_STD = 1,
  PROTOCOL_STREAMING_RPC = 2,
  PROTOCOL_HULU_PBRPC = 3,
  PROTOCOL_SOFA_PBRPC = 4,
  PROTOCOL_RTMP = 5,
  PROTOCOL_THRIFT = 6,
  PROTOCOL_HTTP = 7,
  PROTOCOL_PUBLIC_PBRPC = 8,
  PROTOCOL_NOVA_PBRPC = 9,
  PROTOCOL_REDIS = 10,
  PROTOCOL_NSHEAD_CLIENT = 11,
  PROTOCOL_NSHEAD = 12,
  PROTOCOL_HADOOP_RPC = 13,
  PROTOCOL_HADOOP_SERVER_RPC = 14,
  PROTOCOL_MONGO = 15,
  PROTOCOL_UBRPC_COMPACK = 16,
  PROTOCOL_DIDX_CLIENT = 17,
  PROTOCOL_MEMCACHE = 18,
  PROTOCOL_ITP = 19,
  PROTOCOL_NSHEAD_MCPACK = 20,
  PROTOCOL_DISP_IDL = 21,
  PROTOCOL_ERSDA_CLIENT = 22,
  PROTOCOL_UBRPC_MCPACK2 = 23,
  PROTOCOL_CDS_AGENT = 24,
  PROTOCOL_ESP = 25,
  PROTOCOL_H2 = 26
};
bool ProtocolType_IsValid(int value);
constexpr ProtocolType ProtocolType_MIN = PROTOCOL_UNKNOWN;
constexpr ProtocolType ProtocolType_MAX = PROTOCOL_H2;
constexpr int ProtocolType_ARRAYSIZE = ProtocolType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ProtocolType_descriptor();
template<typename T>
inline const std::string& ProtocolType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ProtocolType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ProtocolType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ProtocolType_descriptor(), enum_t_value);
}
inline bool ProtocolType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ProtocolType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ProtocolType>(
    ProtocolType_descriptor(), name, value);
}
enum CompressType : int {
  COMPRESS_TYPE_NONE = 0,
  COMPRESS_TYPE_SNAPPY = 1,
  COMPRESS_TYPE_GZIP = 2,
  COMPRESS_TYPE_ZLIB = 3,
  COMPRESS_TYPE_LZ4 = 4
};
bool CompressType_IsValid(int value);
constexpr CompressType CompressType_MIN = COMPRESS_TYPE_NONE;
constexpr CompressType CompressType_MAX = COMPRESS_TYPE_LZ4;
constexpr int CompressType_ARRAYSIZE = CompressType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CompressType_descriptor();
template<typename T>
inline const std::string& CompressType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CompressType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CompressType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CompressType_descriptor(), enum_t_value);
}
inline bool CompressType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CompressType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CompressType>(
    CompressType_descriptor(), name, value);
}
// ===================================================================

class ChunkInfo PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:brpc.ChunkInfo) */ {
 public:
  inline ChunkInfo() : ChunkInfo(nullptr) {}
  virtual ~ChunkInfo();

  ChunkInfo(const ChunkInfo& from);
  ChunkInfo(ChunkInfo&& from) noexcept
    : ChunkInfo() {
    *this = ::std::move(from);
  }

  inline ChunkInfo& operator=(const ChunkInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline ChunkInfo& operator=(ChunkInfo&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
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
  static const ChunkInfo& default_instance();

  static inline const ChunkInfo* internal_default_instance() {
    return reinterpret_cast<const ChunkInfo*>(
               &_ChunkInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ChunkInfo& a, ChunkInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(ChunkInfo* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ChunkInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ChunkInfo* New() const final {
    return CreateMaybeMessage<ChunkInfo>(nullptr);
  }

  ChunkInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ChunkInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ChunkInfo& from);
  void MergeFrom(const ChunkInfo& from);
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
  void InternalSwap(ChunkInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "brpc.ChunkInfo";
  }
  protected:
  explicit ChunkInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_brpc_2foptions_2eproto);
    return ::descriptor_table_brpc_2foptions_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStreamIdFieldNumber = 1,
    kChunkIdFieldNumber = 2,
  };
  // required int64 stream_id = 1;
  bool has_stream_id() const;
  private:
  bool _internal_has_stream_id() const;
  public:
  void clear_stream_id();
  ::PROTOBUF_NAMESPACE_ID::int64 stream_id() const;
  void set_stream_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_stream_id() const;
  void _internal_set_stream_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // required int64 chunk_id = 2;
  bool has_chunk_id() const;
  private:
  bool _internal_has_chunk_id() const;
  public:
  void clear_chunk_id();
  ::PROTOBUF_NAMESPACE_ID::int64 chunk_id() const;
  void set_chunk_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_chunk_id() const;
  void _internal_set_chunk_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:brpc.ChunkInfo)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int64 stream_id_;
  ::PROTOBUF_NAMESPACE_ID::int64 chunk_id_;
  friend struct ::TableStruct_brpc_2foptions_2eproto;
};
// ===================================================================

static const int kServiceTimeoutFieldNumber = 90000;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::ServiceOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::PrimitiveTypeTraits< ::PROTOBUF_NAMESPACE_ID::int64 >, 3, false >
  service_timeout;
static const int kRequestTalkTypeFieldNumber = 90001;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::EnumTypeTraits< ::brpc::TalkType, ::brpc::TalkType_IsValid>, 14, false >
  request_talk_type;
static const int kResponseTalkTypeFieldNumber = 90002;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::EnumTypeTraits< ::brpc::TalkType, ::brpc::TalkType_IsValid>, 14, false >
  response_talk_type;
static const int kMethodTimeoutFieldNumber = 90003;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::PrimitiveTypeTraits< ::PROTOBUF_NAMESPACE_ID::int64 >, 3, false >
  method_timeout;
static const int kRequestCompressionFieldNumber = 90004;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::EnumTypeTraits< ::brpc::CompressType, ::brpc::CompressType_IsValid>, 14, false >
  request_compression;
static const int kResponseCompressionFieldNumber = 90005;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::EnumTypeTraits< ::brpc::CompressType, ::brpc::CompressType_IsValid>, 14, false >
  response_compression;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChunkInfo

// required int64 stream_id = 1;
inline bool ChunkInfo::_internal_has_stream_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ChunkInfo::has_stream_id() const {
  return _internal_has_stream_id();
}
inline void ChunkInfo::clear_stream_id() {
  stream_id_ = PROTOBUF_LONGLONG(0);
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ChunkInfo::_internal_stream_id() const {
  return stream_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ChunkInfo::stream_id() const {
  // @@protoc_insertion_point(field_get:brpc.ChunkInfo.stream_id)
  return _internal_stream_id();
}
inline void ChunkInfo::_internal_set_stream_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _has_bits_[0] |= 0x00000001u;
  stream_id_ = value;
}
inline void ChunkInfo::set_stream_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_stream_id(value);
  // @@protoc_insertion_point(field_set:brpc.ChunkInfo.stream_id)
}

// required int64 chunk_id = 2;
inline bool ChunkInfo::_internal_has_chunk_id() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ChunkInfo::has_chunk_id() const {
  return _internal_has_chunk_id();
}
inline void ChunkInfo::clear_chunk_id() {
  chunk_id_ = PROTOBUF_LONGLONG(0);
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ChunkInfo::_internal_chunk_id() const {
  return chunk_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ChunkInfo::chunk_id() const {
  // @@protoc_insertion_point(field_get:brpc.ChunkInfo.chunk_id)
  return _internal_chunk_id();
}
inline void ChunkInfo::_internal_set_chunk_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _has_bits_[0] |= 0x00000002u;
  chunk_id_ = value;
}
inline void ChunkInfo::set_chunk_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_chunk_id(value);
  // @@protoc_insertion_point(field_set:brpc.ChunkInfo.chunk_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace brpc

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::brpc::TalkType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brpc::TalkType>() {
  return ::brpc::TalkType_descriptor();
}
template <> struct is_proto_enum< ::brpc::ConnectionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brpc::ConnectionType>() {
  return ::brpc::ConnectionType_descriptor();
}
template <> struct is_proto_enum< ::brpc::ProtocolType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brpc::ProtocolType>() {
  return ::brpc::ProtocolType_descriptor();
}
template <> struct is_proto_enum< ::brpc::CompressType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brpc::CompressType>() {
  return ::brpc::CompressType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_brpc_2foptions_2eproto
