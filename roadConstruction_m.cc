//
// Generated file, do not edit! Created by opp_msgtool 6.0 from roadConstruction.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "roadConstruction_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace veins {

Register_Class(roadConstruction)

roadConstruction::roadConstruction(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

roadConstruction::roadConstruction(const roadConstruction& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

roadConstruction::~roadConstruction()
{
}

roadConstruction& roadConstruction::operator=(const roadConstruction& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void roadConstruction::copy(const roadConstruction& other)
{
    this->demoData = other.demoData;
    this->Posx = other.Posx;
    this->Posy = other.Posy;
    this->freeLaneID = other.freeLaneID;
    this->ttl = other.ttl;
}

void roadConstruction::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->demoData);
    doParsimPacking(b,this->Posx);
    doParsimPacking(b,this->Posy);
    doParsimPacking(b,this->freeLaneID);
    doParsimPacking(b,this->ttl);
}

void roadConstruction::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->demoData);
    doParsimUnpacking(b,this->Posx);
    doParsimUnpacking(b,this->Posy);
    doParsimUnpacking(b,this->freeLaneID);
    doParsimUnpacking(b,this->ttl);
}

const char * roadConstruction::getDemoData() const
{
    return this->demoData.c_str();
}

void roadConstruction::setDemoData(const char * demoData)
{
    this->demoData = demoData;
}

double roadConstruction::getPosx() const
{
    return this->Posx;
}

void roadConstruction::setPosx(double Posx)
{
    this->Posx = Posx;
}

double roadConstruction::getPosy() const
{
    return this->Posy;
}

void roadConstruction::setPosy(double Posy)
{
    this->Posy = Posy;
}

int roadConstruction::getFreeLaneID() const
{
    return this->freeLaneID;
}

void roadConstruction::setFreeLaneID(int freeLaneID)
{
    this->freeLaneID = freeLaneID;
}

int roadConstruction::getTtl() const
{
    return this->ttl;
}

void roadConstruction::setTtl(int ttl)
{
    this->ttl = ttl;
}

class roadConstructionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_demoData,
        FIELD_Posx,
        FIELD_Posy,
        FIELD_freeLaneID,
        FIELD_ttl,
    };
  public:
    roadConstructionDescriptor();
    virtual ~roadConstructionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(roadConstructionDescriptor)

roadConstructionDescriptor::roadConstructionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::roadConstruction)), "veins::BaseFrame1609_4")
{
    propertyNames = nullptr;
}

roadConstructionDescriptor::~roadConstructionDescriptor()
{
    delete[] propertyNames;
}

bool roadConstructionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<roadConstruction *>(obj)!=nullptr;
}

const char **roadConstructionDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *roadConstructionDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int roadConstructionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int roadConstructionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_demoData
        FD_ISEDITABLE,    // FIELD_Posx
        FD_ISEDITABLE,    // FIELD_Posy
        FD_ISEDITABLE,    // FIELD_freeLaneID
        FD_ISEDITABLE,    // FIELD_ttl
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *roadConstructionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "demoData",
        "Posx",
        "Posy",
        "freeLaneID",
        "ttl",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int roadConstructionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "demoData") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "Posx") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "Posy") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "freeLaneID") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *roadConstructionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_demoData
        "double",    // FIELD_Posx
        "double",    // FIELD_Posy
        "int",    // FIELD_freeLaneID
        "int",    // FIELD_ttl
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **roadConstructionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *roadConstructionDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int roadConstructionDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void roadConstructionDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'roadConstruction'", field);
    }
}

const char *roadConstructionDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string roadConstructionDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: return oppstring2string(pp->getDemoData());
        case FIELD_Posx: return double2string(pp->getPosx());
        case FIELD_Posy: return double2string(pp->getPosy());
        case FIELD_freeLaneID: return long2string(pp->getFreeLaneID());
        case FIELD_ttl: return long2string(pp->getTtl());
        default: return "";
    }
}

void roadConstructionDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: pp->setDemoData((value)); break;
        case FIELD_Posx: pp->setPosx(string2double(value)); break;
        case FIELD_Posy: pp->setPosy(string2double(value)); break;
        case FIELD_freeLaneID: pp->setFreeLaneID(string2long(value)); break;
        case FIELD_ttl: pp->setTtl(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'roadConstruction'", field);
    }
}

omnetpp::cValue roadConstructionDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: return pp->getDemoData();
        case FIELD_Posx: return pp->getPosx();
        case FIELD_Posy: return pp->getPosy();
        case FIELD_freeLaneID: return pp->getFreeLaneID();
        case FIELD_ttl: return pp->getTtl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'roadConstruction' as cValue -- field index out of range?", field);
    }
}

void roadConstructionDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: pp->setDemoData(value.stringValue()); break;
        case FIELD_Posx: pp->setPosx(value.doubleValue()); break;
        case FIELD_Posy: pp->setPosy(value.doubleValue()); break;
        case FIELD_freeLaneID: pp->setFreeLaneID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ttl: pp->setTtl(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'roadConstruction'", field);
    }
}

const char *roadConstructionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr roadConstructionDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void roadConstructionDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    roadConstruction *pp = omnetpp::fromAnyPtr<roadConstruction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'roadConstruction'", field);
    }
}

}  // namespace veins

namespace omnetpp {

}  // namespace omnetpp

