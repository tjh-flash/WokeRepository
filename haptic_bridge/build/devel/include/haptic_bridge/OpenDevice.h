// Generated by gencpp from file haptic_bridge/OpenDevice.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_OPENDEVICE_H
#define HAPTIC_BRIDGE_MESSAGE_OPENDEVICE_H

#include <ros/service_traits.h>


#include <haptic_bridge/OpenDeviceRequest.h>
#include <haptic_bridge/OpenDeviceResponse.h>


namespace haptic_bridge
{

struct OpenDevice
{

typedef OpenDeviceRequest Request;
typedef OpenDeviceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct OpenDevice
} // namespace haptic_bridge


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::haptic_bridge::OpenDevice > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::haptic_bridge::OpenDevice&) { return value(); }
};

template<>
struct DataType< ::haptic_bridge::OpenDevice > {
  static const char* value()
  {
    return "haptic_bridge/OpenDevice";
  }

  static const char* value(const ::haptic_bridge::OpenDevice&) { return value(); }
};


// service_traits::MD5Sum< ::haptic_bridge::OpenDeviceRequest> should match 
// service_traits::MD5Sum< ::haptic_bridge::OpenDevice > 
template<>
struct MD5Sum< ::haptic_bridge::OpenDeviceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::OpenDevice >::value();
  }
  static const char* value(const ::haptic_bridge::OpenDeviceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::OpenDeviceRequest> should match 
// service_traits::DataType< ::haptic_bridge::OpenDevice > 
template<>
struct DataType< ::haptic_bridge::OpenDeviceRequest>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::OpenDevice >::value();
  }
  static const char* value(const ::haptic_bridge::OpenDeviceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::haptic_bridge::OpenDeviceResponse> should match 
// service_traits::MD5Sum< ::haptic_bridge::OpenDevice > 
template<>
struct MD5Sum< ::haptic_bridge::OpenDeviceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::OpenDevice >::value();
  }
  static const char* value(const ::haptic_bridge::OpenDeviceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::OpenDeviceResponse> should match 
// service_traits::DataType< ::haptic_bridge::OpenDevice > 
template<>
struct DataType< ::haptic_bridge::OpenDeviceResponse>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::OpenDevice >::value();
  }
  static const char* value(const ::haptic_bridge::OpenDeviceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_OPENDEVICE_H