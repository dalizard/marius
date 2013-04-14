// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: code.proto

#ifndef PROTOBUF_code_2eproto__INCLUDED
#define PROTOBUF_code_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace serialize {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_code_2eproto();
void protobuf_AssignDesc_code_2eproto();
void protobuf_ShutdownFile_code_2eproto();

class ArgEntry;
class ArgMap;
class Code;

// ===================================================================

class ArgEntry : public ::google::protobuf::Message {
 public:
  ArgEntry();
  virtual ~ArgEntry();
  
  ArgEntry(const ArgEntry& from);
  
  inline ArgEntry& operator=(const ArgEntry& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ArgEntry& default_instance();
  
  void Swap(ArgEntry* other);
  
  // implements Message ----------------------------------------------
  
  ArgEntry* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArgEntry& from);
  void MergeFrom(const ArgEntry& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string key = 1;
  inline bool has_key() const;
  inline void clear_key();
  static const int kKeyFieldNumber = 1;
  inline const ::std::string& key() const;
  inline void set_key(const ::std::string& value);
  inline void set_key(const char* value);
  inline void set_key(const char* value, size_t size);
  inline ::std::string* mutable_key();
  inline ::std::string* release_key();
  
  // required int32 value = 2;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 2;
  inline ::google::protobuf::int32 value() const;
  inline void set_value(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:serialize.ArgEntry)
 private:
  inline void set_has_key();
  inline void clear_has_key();
  inline void set_has_value();
  inline void clear_has_value();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* key_;
  ::google::protobuf::int32 value_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_code_2eproto();
  friend void protobuf_AssignDesc_code_2eproto();
  friend void protobuf_ShutdownFile_code_2eproto();
  
  void InitAsDefaultInstance();
  static ArgEntry* default_instance_;
};
// -------------------------------------------------------------------

class ArgMap : public ::google::protobuf::Message {
 public:
  ArgMap();
  virtual ~ArgMap();
  
  ArgMap(const ArgMap& from);
  
  inline ArgMap& operator=(const ArgMap& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ArgMap& default_instance();
  
  void Swap(ArgMap* other);
  
  // implements Message ----------------------------------------------
  
  ArgMap* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArgMap& from);
  void MergeFrom(const ArgMap& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated .serialize.ArgEntry entries = 1;
  inline int entries_size() const;
  inline void clear_entries();
  static const int kEntriesFieldNumber = 1;
  inline const ::serialize::ArgEntry& entries(int index) const;
  inline ::serialize::ArgEntry* mutable_entries(int index);
  inline ::serialize::ArgEntry* add_entries();
  inline const ::google::protobuf::RepeatedPtrField< ::serialize::ArgEntry >&
      entries() const;
  inline ::google::protobuf::RepeatedPtrField< ::serialize::ArgEntry >*
      mutable_entries();
  
  // @@protoc_insertion_point(class_scope:serialize.ArgMap)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::RepeatedPtrField< ::serialize::ArgEntry > entries_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_code_2eproto();
  friend void protobuf_AssignDesc_code_2eproto();
  friend void protobuf_ShutdownFile_code_2eproto();
  
  void InitAsDefaultInstance();
  static ArgMap* default_instance_;
};
// -------------------------------------------------------------------

class Code : public ::google::protobuf::Message {
 public:
  Code();
  virtual ~Code();
  
  Code(const Code& from);
  
  inline Code& operator=(const Code& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Code& default_instance();
  
  void Swap(Code* other);
  
  // implements Message ----------------------------------------------
  
  Code* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Code& from);
  void MergeFrom(const Code& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  
  // repeated int32 instructions = 2;
  inline int instructions_size() const;
  inline void clear_instructions();
  static const int kInstructionsFieldNumber = 2;
  inline ::google::protobuf::int32 instructions(int index) const;
  inline void set_instructions(int index, ::google::protobuf::int32 value);
  inline void add_instructions(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      instructions() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_instructions();
  
  // repeated string strings = 3;
  inline int strings_size() const;
  inline void clear_strings();
  static const int kStringsFieldNumber = 3;
  inline const ::std::string& strings(int index) const;
  inline ::std::string* mutable_strings(int index);
  inline void set_strings(int index, const ::std::string& value);
  inline void set_strings(int index, const char* value);
  inline void set_strings(int index, const char* value, size_t size);
  inline ::std::string* add_strings();
  inline void add_strings(const ::std::string& value);
  inline void add_strings(const char* value);
  inline void add_strings(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& strings() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_strings();
  
  // repeated .serialize.Code codes = 4;
  inline int codes_size() const;
  inline void clear_codes();
  static const int kCodesFieldNumber = 4;
  inline const ::serialize::Code& codes(int index) const;
  inline ::serialize::Code* mutable_codes(int index);
  inline ::serialize::Code* add_codes();
  inline const ::google::protobuf::RepeatedPtrField< ::serialize::Code >&
      codes() const;
  inline ::google::protobuf::RepeatedPtrField< ::serialize::Code >*
      mutable_codes();
  
  // optional .serialize.ArgMap args = 5;
  inline bool has_args() const;
  inline void clear_args();
  static const int kArgsFieldNumber = 5;
  inline const ::serialize::ArgMap& args() const;
  inline ::serialize::ArgMap* mutable_args();
  inline ::serialize::ArgMap* release_args();
  
  // repeated .serialize.ArgMap keywords = 6;
  inline int keywords_size() const;
  inline void clear_keywords();
  static const int kKeywordsFieldNumber = 6;
  inline const ::serialize::ArgMap& keywords(int index) const;
  inline ::serialize::ArgMap* mutable_keywords(int index);
  inline ::serialize::ArgMap* add_keywords();
  inline const ::google::protobuf::RepeatedPtrField< ::serialize::ArgMap >&
      keywords() const;
  inline ::google::protobuf::RepeatedPtrField< ::serialize::ArgMap >*
      mutable_keywords();
  
  // required int32 closed_over_vars = 7;
  inline bool has_closed_over_vars() const;
  inline void clear_closed_over_vars();
  static const int kClosedOverVarsFieldNumber = 7;
  inline ::google::protobuf::int32 closed_over_vars() const;
  inline void set_closed_over_vars(::google::protobuf::int32 value);
  
  // optional int32 return_to = 8;
  inline bool has_return_to() const;
  inline void clear_return_to();
  static const int kReturnToFieldNumber = 8;
  inline ::google::protobuf::int32 return_to() const;
  inline void set_return_to(::google::protobuf::int32 value);
  
  // optional int32 required_args = 9;
  inline bool has_required_args() const;
  inline void clear_required_args();
  static const int kRequiredArgsFieldNumber = 9;
  inline ::google::protobuf::int32 required_args() const;
  inline void set_required_args(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:serialize.Code)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_args();
  inline void clear_has_args();
  inline void set_has_closed_over_vars();
  inline void clear_has_closed_over_vars();
  inline void set_has_return_to();
  inline void clear_has_return_to();
  inline void set_has_required_args();
  inline void clear_has_required_args();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* name_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > instructions_;
  ::google::protobuf::RepeatedPtrField< ::std::string> strings_;
  ::google::protobuf::RepeatedPtrField< ::serialize::Code > codes_;
  ::serialize::ArgMap* args_;
  ::google::protobuf::RepeatedPtrField< ::serialize::ArgMap > keywords_;
  ::google::protobuf::int32 closed_over_vars_;
  ::google::protobuf::int32 return_to_;
  ::google::protobuf::int32 required_args_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(9 + 31) / 32];
  
  friend void  protobuf_AddDesc_code_2eproto();
  friend void protobuf_AssignDesc_code_2eproto();
  friend void protobuf_ShutdownFile_code_2eproto();
  
  void InitAsDefaultInstance();
  static Code* default_instance_;
};
// ===================================================================


// ===================================================================

// ArgEntry

// required string key = 1;
inline bool ArgEntry::has_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ArgEntry::set_has_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ArgEntry::clear_has_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ArgEntry::clear_key() {
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    key_->clear();
  }
  clear_has_key();
}
inline const ::std::string& ArgEntry::key() const {
  return *key_;
}
inline void ArgEntry::set_key(const ::std::string& value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void ArgEntry::set_key(const char* value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void ArgEntry::set_key(const char* value, size_t size) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  key_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ArgEntry::mutable_key() {
  set_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    key_ = new ::std::string;
  }
  return key_;
}
inline ::std::string* ArgEntry::release_key() {
  clear_has_key();
  if (key_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = key_;
    key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required int32 value = 2;
inline bool ArgEntry::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ArgEntry::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ArgEntry::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ArgEntry::clear_value() {
  value_ = 0;
  clear_has_value();
}
inline ::google::protobuf::int32 ArgEntry::value() const {
  return value_;
}
inline void ArgEntry::set_value(::google::protobuf::int32 value) {
  set_has_value();
  value_ = value;
}

// -------------------------------------------------------------------

// ArgMap

// repeated .serialize.ArgEntry entries = 1;
inline int ArgMap::entries_size() const {
  return entries_.size();
}
inline void ArgMap::clear_entries() {
  entries_.Clear();
}
inline const ::serialize::ArgEntry& ArgMap::entries(int index) const {
  return entries_.Get(index);
}
inline ::serialize::ArgEntry* ArgMap::mutable_entries(int index) {
  return entries_.Mutable(index);
}
inline ::serialize::ArgEntry* ArgMap::add_entries() {
  return entries_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::serialize::ArgEntry >&
ArgMap::entries() const {
  return entries_;
}
inline ::google::protobuf::RepeatedPtrField< ::serialize::ArgEntry >*
ArgMap::mutable_entries() {
  return &entries_;
}

// -------------------------------------------------------------------

// Code

// required string name = 1;
inline bool Code::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Code::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Code::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Code::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Code::name() const {
  return *name_;
}
inline void Code::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Code::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Code::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Code::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Code::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated int32 instructions = 2;
inline int Code::instructions_size() const {
  return instructions_.size();
}
inline void Code::clear_instructions() {
  instructions_.Clear();
}
inline ::google::protobuf::int32 Code::instructions(int index) const {
  return instructions_.Get(index);
}
inline void Code::set_instructions(int index, ::google::protobuf::int32 value) {
  instructions_.Set(index, value);
}
inline void Code::add_instructions(::google::protobuf::int32 value) {
  instructions_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Code::instructions() const {
  return instructions_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Code::mutable_instructions() {
  return &instructions_;
}

// repeated string strings = 3;
inline int Code::strings_size() const {
  return strings_.size();
}
inline void Code::clear_strings() {
  strings_.Clear();
}
inline const ::std::string& Code::strings(int index) const {
  return strings_.Get(index);
}
inline ::std::string* Code::mutable_strings(int index) {
  return strings_.Mutable(index);
}
inline void Code::set_strings(int index, const ::std::string& value) {
  strings_.Mutable(index)->assign(value);
}
inline void Code::set_strings(int index, const char* value) {
  strings_.Mutable(index)->assign(value);
}
inline void Code::set_strings(int index, const char* value, size_t size) {
  strings_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Code::add_strings() {
  return strings_.Add();
}
inline void Code::add_strings(const ::std::string& value) {
  strings_.Add()->assign(value);
}
inline void Code::add_strings(const char* value) {
  strings_.Add()->assign(value);
}
inline void Code::add_strings(const char* value, size_t size) {
  strings_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Code::strings() const {
  return strings_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Code::mutable_strings() {
  return &strings_;
}

// repeated .serialize.Code codes = 4;
inline int Code::codes_size() const {
  return codes_.size();
}
inline void Code::clear_codes() {
  codes_.Clear();
}
inline const ::serialize::Code& Code::codes(int index) const {
  return codes_.Get(index);
}
inline ::serialize::Code* Code::mutable_codes(int index) {
  return codes_.Mutable(index);
}
inline ::serialize::Code* Code::add_codes() {
  return codes_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::serialize::Code >&
Code::codes() const {
  return codes_;
}
inline ::google::protobuf::RepeatedPtrField< ::serialize::Code >*
Code::mutable_codes() {
  return &codes_;
}

// optional .serialize.ArgMap args = 5;
inline bool Code::has_args() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Code::set_has_args() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Code::clear_has_args() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Code::clear_args() {
  if (args_ != NULL) args_->::serialize::ArgMap::Clear();
  clear_has_args();
}
inline const ::serialize::ArgMap& Code::args() const {
  return args_ != NULL ? *args_ : *default_instance_->args_;
}
inline ::serialize::ArgMap* Code::mutable_args() {
  set_has_args();
  if (args_ == NULL) args_ = new ::serialize::ArgMap;
  return args_;
}
inline ::serialize::ArgMap* Code::release_args() {
  clear_has_args();
  ::serialize::ArgMap* temp = args_;
  args_ = NULL;
  return temp;
}

// repeated .serialize.ArgMap keywords = 6;
inline int Code::keywords_size() const {
  return keywords_.size();
}
inline void Code::clear_keywords() {
  keywords_.Clear();
}
inline const ::serialize::ArgMap& Code::keywords(int index) const {
  return keywords_.Get(index);
}
inline ::serialize::ArgMap* Code::mutable_keywords(int index) {
  return keywords_.Mutable(index);
}
inline ::serialize::ArgMap* Code::add_keywords() {
  return keywords_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::serialize::ArgMap >&
Code::keywords() const {
  return keywords_;
}
inline ::google::protobuf::RepeatedPtrField< ::serialize::ArgMap >*
Code::mutable_keywords() {
  return &keywords_;
}

// required int32 closed_over_vars = 7;
inline bool Code::has_closed_over_vars() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Code::set_has_closed_over_vars() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Code::clear_has_closed_over_vars() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Code::clear_closed_over_vars() {
  closed_over_vars_ = 0;
  clear_has_closed_over_vars();
}
inline ::google::protobuf::int32 Code::closed_over_vars() const {
  return closed_over_vars_;
}
inline void Code::set_closed_over_vars(::google::protobuf::int32 value) {
  set_has_closed_over_vars();
  closed_over_vars_ = value;
}

// optional int32 return_to = 8;
inline bool Code::has_return_to() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Code::set_has_return_to() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Code::clear_has_return_to() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Code::clear_return_to() {
  return_to_ = 0;
  clear_has_return_to();
}
inline ::google::protobuf::int32 Code::return_to() const {
  return return_to_;
}
inline void Code::set_return_to(::google::protobuf::int32 value) {
  set_has_return_to();
  return_to_ = value;
}

// optional int32 required_args = 9;
inline bool Code::has_required_args() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Code::set_has_required_args() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Code::clear_has_required_args() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Code::clear_required_args() {
  required_args_ = 0;
  clear_has_required_args();
}
inline ::google::protobuf::int32 Code::required_args() const {
  return required_args_;
}
inline void Code::set_required_args(::google::protobuf::int32 value) {
  set_has_required_args();
  required_args_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace serialize

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_code_2eproto__INCLUDED
