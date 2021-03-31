// Generated by gencpp from file haptic_bridge/StartControlRequest.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_STARTCONTROLREQUEST_H
#define HAPTIC_BRIDGE_MESSAGE_STARTCONTROLREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace haptic_bridge
{
template <class ContainerAllocator>
struct StartControlRequest_
{
  typedef StartControlRequest_<ContainerAllocator> Type;

  StartControlRequest_()
    : isControl(false)  {
    }
  StartControlRequest_(const ContainerAllocator& _alloc)
    : isControl(false)  {
  (void)_alloc;
    }



   typedef uint8_t _isControl_type;
  _isControl_type isControl;





  typedef boost::shared_ptr< ::haptic_bridge::StartControlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::haptic_bridge::StartControlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct StartControlRequest_

typedef ::haptic_bridge::StartControlRequest_<std::allocator<void> > StartControlRequest;

typedef boost::shared_ptr< ::haptic_bridge::StartControlRequest > StartControlRequestPtr;
typedef boost::shared_ptr< ::haptic_bridge::StartControlRequest const> StartControlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::haptic_bridge::StartControlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace haptic_bridge

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::haptic_bridge::StartControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::haptic_bridge::StartControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::haptic_bridge::StartControlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "99bedf6bf4f1b97105db84a2d5232627";
  }

  static const char* value(const ::haptic_bridge::StartControlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x99bedf6bf4f1b971ULL;
  static const uint64_t static_value2 = 0x05db84a2d5232627ULL;
};

template<class ContainerAllocator>
struct DataType< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "haptic_bridge/StartControlRequest";
  }

  static const char* value(const ::haptic_bridge::StartControlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool isControl\n\
";
  }

  static const char* value(const ::haptic_bridge::StartControlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.isControl);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StartControlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::haptic_bridge::StartControlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::haptic_bridge::StartControlRequest_<ContainerAllocator>& v)
  {
    s << indent << "isControl: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isControl);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_STARTCONTROLREQUEST_H