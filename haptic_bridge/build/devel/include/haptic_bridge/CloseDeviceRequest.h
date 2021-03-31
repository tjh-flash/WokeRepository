// Generated by gencpp from file haptic_bridge/CloseDeviceRequest.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICEREQUEST_H
#define HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICEREQUEST_H


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
struct CloseDeviceRequest_
{
  typedef CloseDeviceRequest_<ContainerAllocator> Type;

  CloseDeviceRequest_()
    {
    }
  CloseDeviceRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CloseDeviceRequest_

typedef ::haptic_bridge::CloseDeviceRequest_<std::allocator<void> > CloseDeviceRequest;

typedef boost::shared_ptr< ::haptic_bridge::CloseDeviceRequest > CloseDeviceRequestPtr;
typedef boost::shared_ptr< ::haptic_bridge::CloseDeviceRequest const> CloseDeviceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "haptic_bridge/CloseDeviceRequest";
  }

  static const char* value(const ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CloseDeviceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::haptic_bridge::CloseDeviceRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICEREQUEST_H
