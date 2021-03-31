; Auto-generated. Do not edit!


(cl:in-package haptic_bridge-srv)


;//! \htmlinclude StartControl-request.msg.html

(cl:defclass <StartControl-request> (roslisp-msg-protocol:ros-message)
  ((isControl
    :reader isControl
    :initarg :isControl
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass StartControl-request (<StartControl-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartControl-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartControl-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<StartControl-request> is deprecated: use haptic_bridge-srv:StartControl-request instead.")))

(cl:ensure-generic-function 'isControl-val :lambda-list '(m))
(cl:defmethod isControl-val ((m <StartControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:isControl-val is deprecated.  Use haptic_bridge-srv:isControl instead.")
  (isControl m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartControl-request>) ostream)
  "Serializes a message object of type '<StartControl-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isControl) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartControl-request>) istream)
  "Deserializes a message object of type '<StartControl-request>"
    (cl:setf (cl:slot-value msg 'isControl) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartControl-request>)))
  "Returns string type for a service object of type '<StartControl-request>"
  "haptic_bridge/StartControlRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartControl-request)))
  "Returns string type for a service object of type 'StartControl-request"
  "haptic_bridge/StartControlRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartControl-request>)))
  "Returns md5sum for a message object of type '<StartControl-request>"
  "99bedf6bf4f1b97105db84a2d5232627")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartControl-request)))
  "Returns md5sum for a message object of type 'StartControl-request"
  "99bedf6bf4f1b97105db84a2d5232627")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartControl-request>)))
  "Returns full string definition for message of type '<StartControl-request>"
  (cl:format cl:nil "bool isControl~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartControl-request)))
  "Returns full string definition for message of type 'StartControl-request"
  (cl:format cl:nil "bool isControl~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartControl-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartControl-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartControl-request
    (cl:cons ':isControl (isControl msg))
))
;//! \htmlinclude StartControl-response.msg.html

(cl:defclass <StartControl-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass StartControl-response (<StartControl-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartControl-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartControl-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<StartControl-response> is deprecated: use haptic_bridge-srv:StartControl-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartControl-response>) ostream)
  "Serializes a message object of type '<StartControl-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartControl-response>) istream)
  "Deserializes a message object of type '<StartControl-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartControl-response>)))
  "Returns string type for a service object of type '<StartControl-response>"
  "haptic_bridge/StartControlResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartControl-response)))
  "Returns string type for a service object of type 'StartControl-response"
  "haptic_bridge/StartControlResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartControl-response>)))
  "Returns md5sum for a message object of type '<StartControl-response>"
  "99bedf6bf4f1b97105db84a2d5232627")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartControl-response)))
  "Returns md5sum for a message object of type 'StartControl-response"
  "99bedf6bf4f1b97105db84a2d5232627")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartControl-response>)))
  "Returns full string definition for message of type '<StartControl-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartControl-response)))
  "Returns full string definition for message of type 'StartControl-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartControl-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartControl-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartControl-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartControl)))
  'StartControl-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartControl)))
  'StartControl-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartControl)))
  "Returns string type for a service object of type '<StartControl>"
  "haptic_bridge/StartControl")