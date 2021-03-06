// Generated by gencpp from file haptic_bridge/StartControl.msg
// DO NOT EDIT!


#ifndef HAPTIC_BRIDGE_MESSAGE_STARTCONTROL_H
#define HAPTIC_BRIDGE_MESSAGE_STARTCONTROL_H

#include <ros/service_traits.h>


#include <haptic_bridge/StartControlRequest.h>
#include <haptic_bridge/StartControlResponse.h>


namespace haptic_bridge
{

struct StartControl
{

typedef StartControlRequest Request;
typedef StartControlResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StartControl
} // namespace haptic_bridge


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::haptic_bridge::StartControl > {
  static const char* value()
  {
    return "99bedf6bf4f1b97105db84a2d5232627";
  }

  static const char* value(const ::haptic_bridge::StartControl&) { return value(); }
};

template<>
struct DataType< ::haptic_bridge::StartControl > {
  static const char* value()
  {
    return "haptic_bridge/StartControl";
  }

  static const char* value(const ::haptic_bridge::StartControl&) { return value(); }
};


// service_traits::MD5Sum< ::haptic_bridge::StartControlRequest> should match 
// service_traits::MD5Sum< ::haptic_bridge::StartControl > 
template<>
struct MD5Sum< ::haptic_bridge::StartControlRequest>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::StartControl >::value();
  }
  static const char* value(const ::haptic_bridge::StartControlRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::StartControlRequest> should match 
// service_traits::DataType< ::haptic_bridge::StartControl > 
template<>
struct DataType< ::haptic_bridge::StartControlRequest>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::StartControl >::value();
  }
  static const char* value(const ::haptic_bridge::StartControlRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::haptic_bridge::StartControlResponse> should match 
// service_traits::MD5Sum< ::haptic_bridge::StartControl > 
template<>
struct MD5Sum< ::haptic_bridge::StartControlResponse>
{
  static const char* value()
  {
    return MD5Sum< ::haptic_bridge::StartControl >::value();
  }
  static const char* value(const ::haptic_bridge::StartControlResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::haptic_bridge::StartControlResponse> should match 
// service_traits::DataType< ::haptic_bridge::StartControl > 
template<>
struct DataType< ::haptic_bridge::StartControlResponse>
{
  static const char* value()
  {
    return DataType< ::haptic_bridge::StartControl >::value();
  }
  static const char* value(const ::haptic_bridge::StartControlResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HAPTIC_BRIDGE_MESSAGE_STARTCONTROL_H
