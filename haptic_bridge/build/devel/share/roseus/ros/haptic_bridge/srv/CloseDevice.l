;; Auto-generated. Do not edit!


(when (boundp 'haptic_bridge::CloseDevice)
  (if (not (find-package "HAPTIC_BRIDGE"))
    (make-package "HAPTIC_BRIDGE"))
  (shadow 'CloseDevice (find-package "HAPTIC_BRIDGE")))
(unless (find-package "HAPTIC_BRIDGE::CLOSEDEVICE")
  (make-package "HAPTIC_BRIDGE::CLOSEDEVICE"))
(unless (find-package "HAPTIC_BRIDGE::CLOSEDEVICEREQUEST")
  (make-package "HAPTIC_BRIDGE::CLOSEDEVICEREQUEST"))
(unless (find-package "HAPTIC_BRIDGE::CLOSEDEVICERESPONSE")
  (make-package "HAPTIC_BRIDGE::CLOSEDEVICERESPONSE"))

(in-package "ROS")





(defclass haptic_bridge::CloseDeviceRequest
  :super ros::object
  :slots ())

(defmethod haptic_bridge::CloseDeviceRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass haptic_bridge::CloseDeviceResponse
  :super ros::object
  :slots ())

(defmethod haptic_bridge::CloseDeviceResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass haptic_bridge::CloseDevice
  :super ros::object
  :slots ())

(setf (get haptic_bridge::CloseDevice :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::CloseDevice :datatype-) "haptic_bridge/CloseDevice")
(setf (get haptic_bridge::CloseDevice :request) haptic_bridge::CloseDeviceRequest)
(setf (get haptic_bridge::CloseDevice :response) haptic_bridge::CloseDeviceResponse)

(defmethod haptic_bridge::CloseDeviceRequest
  (:response () (instance haptic_bridge::CloseDeviceResponse :init)))

(setf (get haptic_bridge::CloseDeviceRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::CloseDeviceRequest :datatype-) "haptic_bridge/CloseDeviceRequest")
(setf (get haptic_bridge::CloseDeviceRequest :definition-)
      "
---
")

(setf (get haptic_bridge::CloseDeviceResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::CloseDeviceResponse :datatype-) "haptic_bridge/CloseDeviceResponse")
(setf (get haptic_bridge::CloseDeviceResponse :definition-)
      "
---
")



(provide :haptic_bridge/CloseDevice "d41d8cd98f00b204e9800998ecf8427e")


