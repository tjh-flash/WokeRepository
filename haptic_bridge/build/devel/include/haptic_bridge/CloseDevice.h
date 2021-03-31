// Generated by gencpp from file haptic_bridge/CloseDevice.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICE_H
#define HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICE_H

#include <ros/service_traits.h>


#include <haptic_bridge/CloseDeviceRequest.h>
#include <haptic_bridge/CloseDeviceResponse.h>


namespace haptic_bridge
{

struct CloseDevice
{

typedef CloseDeviceRequest Request;
typedef CloseDeviceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct CloseDevice
} // namespace haptic_bridge


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::haptic_bridge::CloseDevice > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::haptic_bridge::CloseDevice&) { return value(); }
};

template<>
struct DataType< ::haptic_bridge::CloseDevice > {
  static const char* value()
  {
    return "haptic_bridge/CloseDevice";
  }

  static const char* value(const ::haptic_bridge::CloseDevice&) { return value(); }
};


// service_traits::MD5Sum< ::haptic_bridge::CloseDeviceRequest> should match 
// service_traits::MD5Sum< ::haptic_bridge::CloseDevice > 
template<>
struct MD5Sum< ::haptic_bridge::CloseDeviceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::CloseDevice >::value();
  }
  static const char* value(const ::haptic_bridge::CloseDeviceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::CloseDeviceRequest> should match 
// service_traits::DataType< ::haptic_bridge::CloseDevice > 
template<>
struct DataType< ::haptic_bridge::CloseDeviceRequest>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::CloseDevice >::value();
  }
  static const char* value(const ::haptic_bridge::CloseDeviceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::haptic_bridge::CloseDeviceResponse> should match 
// service_traits::MD5Sum< ::haptic_bridge::CloseDevice > 
template<>
struct MD5Sum< ::haptic_bridge::CloseDeviceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::CloseDevice >::value();
  }
  static const char* value(const ::haptic_bridge::CloseDeviceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::CloseDeviceResponse> should match 
// service_traits::DataType< ::haptic_bridge::CloseDevice > 
template<>
struct DataType< ::haptic_bridge::CloseDeviceResponse>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::CloseDevice >::value();
  }
  static const char* value(const ::haptic_bridge::CloseDeviceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_CLOSEDEVICE_H
