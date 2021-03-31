; Auto-generated. Do not edit!


(cl:in-package haptic_bridge-srv)


;//! \htmlinclude OpenDevice-request.msg.html

(cl:defclass <OpenDevice-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass OpenDevice-request (<OpenDevice-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OpenDevice-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OpenDevice-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<OpenDevice-request> is deprecated: use haptic_bridge-srv:OpenDevice-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OpenDevice-request>) ostream)
  "Serializes a message object of type '<OpenDevice-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OpenDevice-request>) istream)
  "Deserializes a message object of type '<OpenDevice-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OpenDevice-request>)))
  "Returns string type for a service object of type '<OpenDevice-request>"
  "haptic_bridge/OpenDeviceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OpenDevice-request)))
  "Returns string type for a service object of type 'OpenDevice-request"
  "haptic_bridge/OpenDeviceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OpenDevice-request>)))
  "Returns md5sum for a message object of type '<OpenDevice-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OpenDevice-request)))
  "Returns md5sum for a message object of type 'OpenDevice-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OpenDevice-request>)))
  "Returns full string definition for message of type '<OpenDevice-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OpenDevice-request)))
  "Returns full string definition for message of type 'OpenDevice-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OpenDevice-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OpenDevice-request>))
  "Converts a ROS message object to a list"
  (cl:list 'OpenDevice-request
))
;//! \htmlinclude OpenDevice-response.msg.html

(cl:defclass <OpenDevice-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass OpenDevice-response (<OpenDevice-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OpenDevice-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OpenDevice-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<OpenDevice-response> is deprecated: use haptic_bridge-srv:OpenDevice-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OpenDevice-response>) ostream)
  "Serializes a message object of type '<OpenDevice-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OpenDevice-response>) istream)
  "Deserializes a message object of type '<OpenDevice-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OpenDevice-response>)))
  "Returns string type for a service object of type '<OpenDevice-response>"
  "haptic_bridge/OpenDeviceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OpenDevice-response)))
  "Returns string type for a service object of type 'OpenDevice-response"
  "haptic_bridge/OpenDeviceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OpenDevice-response>)))
  "Returns md5sum for a message object of type '<OpenDevice-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OpenDevice-response)))
  "Returns md5sum for a message object of type 'OpenDevice-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OpenDevice-response>)))
  "Returns full string definition for message of type '<OpenDevice-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OpenDevice-response)))
  "Returns full string definition for message of type 'OpenDevice-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OpenDevice-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OpenDevice-response>))
  "Converts a ROS message object to a list"
  (cl:list 'OpenDevice-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'OpenDevice)))
  'OpenDevice-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'OpenDevice)))
  'OpenDevice-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OpenDevice)))
  "Returns string type for a service object of type '<OpenDevice>"
  "haptic_bridge/OpenDevice")