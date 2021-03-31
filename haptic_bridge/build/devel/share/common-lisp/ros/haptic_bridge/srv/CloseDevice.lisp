; Auto-generated. Do not edit!


(cl:in-package haptic_bridge-srv)


;//! \htmlinclude CloseDevice-request.msg.html

(cl:defclass <CloseDevice-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass CloseDevice-request (<CloseDevice-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CloseDevice-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CloseDevice-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<CloseDevice-request> is deprecated: use haptic_bridge-srv:CloseDevice-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CloseDevice-request>) ostream)
  "Serializes a message object of type '<CloseDevice-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CloseDevice-request>) istream)
  "Deserializes a message object of type '<CloseDevice-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CloseDevice-request>)))
  "Returns string type for a service object of type '<CloseDevice-request>"
  "haptic_bridge/CloseDeviceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CloseDevice-request)))
  "Returns string type for a service object of type 'CloseDevice-request"
  "haptic_bridge/CloseDeviceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CloseDevice-request>)))
  "Returns md5sum for a message object of type '<CloseDevice-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CloseDevice-request)))
  "Returns md5sum for a message object of type 'CloseDevice-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CloseDevice-request>)))
  "Returns full string definition for message of type '<CloseDevice-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CloseDevice-request)))
  "Returns full string definition for message of type 'CloseDevice-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CloseDevice-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CloseDevice-request>))
  "Converts a ROS message object to a list"
  (cl:list 'CloseDevice-request
))
;//! \htmlinclude CloseDevice-response.msg.html

(cl:defclass <CloseDevice-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass CloseDevice-response (<CloseDevice-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CloseDevice-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CloseDevice-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<CloseDevice-response> is deprecated: use haptic_bridge-srv:CloseDevice-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CloseDevice-response>) ostream)
  "Serializes a message object of type '<CloseDevice-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CloseDevice-response>) istream)
  "Deserializes a message object of type '<CloseDevice-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CloseDevice-response>)))
  "Returns string type for a service object of type '<CloseDevice-response>"
  "haptic_bridge/CloseDeviceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CloseDevice-response)))
  "Returns string type for a service object of type 'CloseDevice-response"
  "haptic_bridge/CloseDeviceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CloseDevice-response>)))
  "Returns md5sum for a message object of type '<CloseDevice-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CloseDevice-response)))
  "Returns md5sum for a message object of type 'CloseDevice-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CloseDevice-response>)))
  "Returns full string definition for message of type '<CloseDevice-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CloseDevice-response)))
  "Returns full string definition for message of type 'CloseDevice-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CloseDevice-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CloseDevice-response>))
  "Converts a ROS message object to a list"
  (cl:list 'CloseDevice-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'CloseDevice)))
  'CloseDevice-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'CloseDevice)))
  'CloseDevice-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CloseDevice)))
  "Returns string type for a service object of type '<CloseDevice>"
  "haptic_bridge/CloseDevice")