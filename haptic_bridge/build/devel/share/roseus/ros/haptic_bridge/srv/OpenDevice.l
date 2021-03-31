;; Auto-generated. Do not edit!


(when (boundp 'haptic_bridge::OpenDevice)
  (if (not (find-package "HAPTIC_BRIDGE"))
    (make-package "HAPTIC_BRIDGE"))
  (shadow 'OpenDevice (find-package "HAPTIC_BRIDGE")))
(unless (find-package "HAPTIC_BRIDGE::OPENDEVICE")
  (make-package "HAPTIC_BRIDGE::OPENDEVICE"))
(unless (find-package "HAPTIC_BRIDGE::OPENDEVICEREQUEST")
  (make-package "HAPTIC_BRIDGE::OPENDEVICEREQUEST"))
(unless (find-package "HAPTIC_BRIDGE::OPENDEVICERESPONSE")
  (make-package "HAPTIC_BRIDGE::OPENDEVICERESPONSE"))

(in-package "ROS")





(defclass haptic_bridge::OpenDeviceRequest
  :super ros::object
  :slots ())

(defmethod haptic_bridge::OpenDeviceRequest
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

(defclass haptic_bridge::OpenDeviceResponse
  :super ros::object
  :slots ())

(defmethod haptic_bridge::OpenDeviceResponse
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

(defclass haptic_bridge::OpenDevice
  :super ros::object
  :slots ())

(setf (get haptic_bridge::OpenDevice :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::OpenDevice :datatype-) "haptic_bridge/OpenDevice")
(setf (get haptic_bridge::OpenDevice :request) haptic_bridge::OpenDeviceRequest)
(setf (get haptic_bridge::OpenDevice :response) haptic_bridge::OpenDeviceResponse)

(defmethod haptic_bridge::OpenDeviceRequest
  (:response () (instance haptic_bridge::OpenDeviceResponse :init)))

(setf (get haptic_bridge::OpenDeviceRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::OpenDeviceRequest :datatype-) "haptic_bridge/OpenDeviceRequest")
(setf (get haptic_bridge::OpenDeviceRequest :definition-)
      "
---
")

(setf (get haptic_bridge::OpenDeviceResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get haptic_bridge::OpenDeviceResponse :datatype-) "haptic_bridge/OpenDeviceResponse")
(setf (get haptic_bridge::OpenDeviceResponse :definition-)
      "
---
")



(provide :haptic_bridge/OpenDevice "d41d8cd98f00b204e9800998ecf8427e")


