; Auto-generated. Do not edit!


(cl:in-package haptic_bridge-srv)


;//! \htmlinclude SwitchAxis-request.msg.html

(cl:defclass <SwitchAxis-request> (roslisp-msg-protocol:ros-message)
  ((Axis_X
    :reader Axis_X
    :initarg :Axis_X
    :type cl:fixnum
    :initform 0)
   (Axis_Y
    :reader Axis_Y
    :initarg :Axis_Y
    :type cl:fixnum
    :initform 0)
   (Axis_Z
    :reader Axis_Z
    :initarg :Axis_Z
    :type cl:fixnum
    :initform 0)
   (Axis_A
    :reader Axis_A
    :initarg :Axis_A
    :type cl:fixnum
    :initform 0)
   (Axis_B
    :reader Axis_B
    :initarg :Axis_B
    :type cl:fixnum
    :initform 0)
   (Axis_C
    :reader Axis_C
    :initarg :Axis_C
    :type cl:fixnum
    :initform 0))
)

(cl:defclass SwitchAxis-request (<SwitchAxis-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SwitchAxis-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SwitchAxis-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<SwitchAxis-request> is deprecated: use haptic_bridge-srv:SwitchAxis-request instead.")))

(cl:ensure-generic-function 'Axis_X-val :lambda-list '(m))
(cl:defmethod Axis_X-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_X-val is deprecated.  Use haptic_bridge-srv:Axis_X instead.")
  (Axis_X m))

(cl:ensure-generic-function 'Axis_Y-val :lambda-list '(m))
(cl:defmethod Axis_Y-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_Y-val is deprecated.  Use haptic_bridge-srv:Axis_Y instead.")
  (Axis_Y m))

(cl:ensure-generic-function 'Axis_Z-val :lambda-list '(m))
(cl:defmethod Axis_Z-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_Z-val is deprecated.  Use haptic_bridge-srv:Axis_Z instead.")
  (Axis_Z m))

(cl:ensure-generic-function 'Axis_A-val :lambda-list '(m))
(cl:defmethod Axis_A-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_A-val is deprecated.  Use haptic_bridge-srv:Axis_A instead.")
  (Axis_A m))

(cl:ensure-generic-function 'Axis_B-val :lambda-list '(m))
(cl:defmethod Axis_B-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_B-val is deprecated.  Use haptic_bridge-srv:Axis_B instead.")
  (Axis_B m))

(cl:ensure-generic-function 'Axis_C-val :lambda-list '(m))
(cl:defmethod Axis_C-val ((m <SwitchAxis-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader haptic_bridge-srv:Axis_C-val is deprecated.  Use haptic_bridge-srv:Axis_C instead.")
  (Axis_C m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SwitchAxis-request>) ostream)
  "Serializes a message object of type '<SwitchAxis-request>"
  (cl:let* ((signed (cl:slot-value msg 'Axis_X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Axis_Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Axis_Z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Axis_A)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Axis_B)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Axis_C)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SwitchAxis-request>) istream)
  "Deserializes a message object of type '<SwitchAxis-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_X) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_Y) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_Z) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_A) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_B) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Axis_C) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SwitchAxis-request>)))
  "Returns string type for a service object of type '<SwitchAxis-request>"
  "haptic_bridge/SwitchAxisRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SwitchAxis-request)))
  "Returns string type for a service object of type 'SwitchAxis-request"
  "haptic_bridge/SwitchAxisRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SwitchAxis-request>)))
  "Returns md5sum for a message object of type '<SwitchAxis-request>"
  "d49f586c863effd36097bed82b38127a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SwitchAxis-request)))
  "Returns md5sum for a message object of type 'SwitchAxis-request"
  "d49f586c863effd36097bed82b38127a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SwitchAxis-request>)))
  "Returns full string definition for message of type '<SwitchAxis-request>"
  (cl:format cl:nil "int8 Axis_X~%int8 Axis_Y~%int8 Axis_Z~%int8 Axis_A~%int8 Axis_B~%int8 Axis_C~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SwitchAxis-request)))
  "Returns full string definition for message of type 'SwitchAxis-request"
  (cl:format cl:nil "int8 Axis_X~%int8 Axis_Y~%int8 Axis_Z~%int8 Axis_A~%int8 Axis_B~%int8 Axis_C~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SwitchAxis-request>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SwitchAxis-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SwitchAxis-request
    (cl:cons ':Axis_X (Axis_X msg))
    (cl:cons ':Axis_Y (Axis_Y msg))
    (cl:cons ':Axis_Z (Axis_Z msg))
    (cl:cons ':Axis_A (Axis_A msg))
    (cl:cons ':Axis_B (Axis_B msg))
    (cl:cons ':Axis_C (Axis_C msg))
))
;//! \htmlinclude SwitchAxis-response.msg.html

(cl:defclass <SwitchAxis-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SwitchAxis-response (<SwitchAxis-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SwitchAxis-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SwitchAxis-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name haptic_bridge-srv:<SwitchAxis-response> is deprecated: use haptic_bridge-srv:SwitchAxis-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SwitchAxis-response>) ostream)
  "Serializes a message object of type '<SwitchAxis-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SwitchAxis-response>) istream)
  "Deserializes a message object of type '<SwitchAxis-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SwitchAxis-response>)))
  "Returns string type for a service object of type '<SwitchAxis-response>"
  "haptic_bridge/SwitchAxisResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SwitchAxis-response)))
  "Returns string type for a service object of type 'SwitchAxis-response"
  "haptic_bridge/SwitchAxisResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SwitchAxis-response>)))
  "Returns md5sum for a message object of type '<SwitchAxis-response>"
  "d49f586c863effd36097bed82b38127a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SwitchAxis-response)))
  "Returns md5sum for a message object of type 'SwitchAxis-response"
  "d49f586c863effd36097bed82b38127a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SwitchAxis-response>)))
  "Returns full string definition for message of type '<SwitchAxis-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SwitchAxis-response)))
  "Returns full string definition for message of type 'SwitchAxis-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SwitchAxis-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SwitchAxis-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SwitchAxis-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SwitchAxis)))
  'SwitchAxis-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SwitchAxis)))
  'SwitchAxis-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SwitchAxis)))
  "Returns string type for a service object of type '<SwitchAxis>"
  "haptic_bridge/SwitchAxis")