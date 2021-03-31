// Generated by gencpp from file haptic_bridge/SwitchAxis.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_SWITCHAXIS_H
#define HAPTIC_BRIDGE_MESSAGE_SWITCHAXIS_H

#include <ros/service_traits.h>


#include <haptic_bridge/SwitchAxisRequest.h>
#include <haptic_bridge/SwitchAxisResponse.h>


namespace haptic_bridge
{

struct SwitchAxis
{

typedef SwitchAxisRequest Request;
typedef SwitchAxisResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SwitchAxis
} // namespace haptic_bridge


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::haptic_bridge::SwitchAxis > {
  static const char* value()
  {
    return "d49f586c863effd36097bed82b38127a";
  }

  static const char* value(const ::haptic_bridge::SwitchAxis&) { return value(); }
};

template<>
struct DataType< ::haptic_bridge::SwitchAxis > {
  static const char* value()
  {
    return "haptic_bridge/SwitchAxis";
  }

  static const char* value(const ::haptic_bridge::SwitchAxis&) { return value(); }
};


// service_traits::MD5Sum< ::haptic_bridge::SwitchAxisRequest> should match 
// service_traits::MD5Sum< ::haptic_bridge::SwitchAxis > 
template<>
struct MD5Sum< ::haptic_bridge::SwitchAxisRequest>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::SwitchAxis >::value();
  }
  static const char* value(const ::haptic_bridge::SwitchAxisRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::SwitchAxisRequest> should match 
// service_traits::DataType< ::haptic_bridge::SwitchAxis > 
template<>
struct DataType< ::haptic_bridge::SwitchAxisRequest>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::SwitchAxis >::value();
  }
  static const char* value(const ::haptic_bridge::SwitchAxisRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::haptic_bridge::SwitchAxisResponse> should match 
// service_traits::MD5Sum< ::haptic_bridge::SwitchAxis > 
template<>
struct MD5Sum< ::haptic_bridge::SwitchAxisResponse>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::SwitchAxis >::value();
  }
  static const char* value(const ::haptic_bridge::SwitchAxisResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::SwitchAxisResponse> should match 
// service_traits::DataType< ::haptic_bridge::SwitchAxis > 
template<>
struct DataType< ::haptic_bridge::SwitchAxisResponse>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::SwitchAxis >::value();
  }
  static const char* value(const ::haptic_bridge::SwitchAxisResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_SWITCHAXIS_H