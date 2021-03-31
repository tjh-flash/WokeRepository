/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef midRosInterface_TYPES_H
#define midRosInterface_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




typedef std::string String;

//typedef int32_t int;

class JointPt;

typedef struct _JointPt__isset {
  _JointPt__isset() : robotId(false), sequence(false), time(false), pos(false), isCart(true) {}
  bool robotId :1;
  bool sequence :1;
  bool time :1;
  bool pos :1;
  bool isCart :1;
} _JointPt__isset;

class JointPt {
 public:

  JointPt(const JointPt&);
  JointPt& operator=(const JointPt&);
  JointPt() : robotId(0), sequence(0), time(0), isCart(0) {
  }

  virtual ~JointPt() throw();
  int32_t robotId;
  int32_t sequence;
  int32_t time;
  std::vector<double>  pos;
  int32_t isCart;

  _JointPt__isset __isset;

  void __set_robotId(const int32_t val);

  void __set_sequence(const int32_t val);

  void __set_time(const int32_t val);

  void __set_pos(const std::vector<double> & val);

  void __set_isCart(const int32_t val);

  bool operator == (const JointPt & rhs) const
  {
    if (!(robotId == rhs.robotId))
      return false;
    if (!(sequence == rhs.sequence))
      return false;
    if (!(time == rhs.time))
      return false;
    if (!(pos == rhs.pos))
      return false;
    if (!(isCart == rhs.isCart))
      return false;
    return true;
  }
  bool operator != (const JointPt &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointPt & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(JointPt &a, JointPt &b);

inline std::ostream& operator<<(std::ostream& out, const JointPt& obj)
{
  obj.printTo(out);
  return out;
}



#endif