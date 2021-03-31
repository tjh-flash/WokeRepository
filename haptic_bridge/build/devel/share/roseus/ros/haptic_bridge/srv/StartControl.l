;; Auto-generated. Do not edit!


(when (boundp 'haptic_bridge::StartControl)
  (if (not (find-package "HAPTIC_BRIDGE"))
    (make-package "HAPTIC_BRIDGE"))
  (shadow 'StartControl (find-package "HAPTIC_BRIDGE")))
(unless (find-package "HAPTIC_BRIDGE::STARTCONTROL")
  (make-package "HAPTIC_BRIDGE::STARTCONTROL"))
(unless (find-package "HAPTIC_BRIDGE::STARTCONTROLREQUEST")
  (make-package "HAPTIC_BRIDGE::STARTCONTROLREQUEST"))
(unless (find-package "HAPTIC_BRIDGE::STARTCONTROLRESPONSE")
  (make-package "HAPTIC_BRIDGE::STARTCONTROLRESPONSE"))

(in-package "ROS")





(defclass haptic_bridge::StartControlRequest
  :super ros::object
  :slots (_isControl ))

(defmethod haptic_bridge::StartControlRequest
  (:init
   (&key
    ((:isControl __isControl) nil)
    )
   (send-super :init)
   (setq _isControl __isControl)
   self)
  (:isControl
   (&optional __isControl)
   (if __isControl (setq _isControl __isControl)) _isControl)
  (:serialization-length
   ()
   (+
    ;; bool _isControl
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isControl
       (if _isControl (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isControl
     (setq _isControl (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass haptic_bridge::StartControlResponse
  :super ros::object
  :slots ())

(defmethod haptic_bridge::StartControlResponse
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

(defclass haptic_bridge::StartControl
  :super ros::object
  :slots ())

(setf (get haptic_bridge::StartControl :md5sum-) "99bedf6bf4f1b97105db84a2d5232627")
(setf (get haptic_bridge::StartControl :datatype-) "haptic_bridge/StartControl")
(setf (get haptic_bridge::StartControl :request) haptic_bridge::StartControlRequest)
(setf (get haptic_bridge::StartControl :response) haptic_bridge::StartControlResponse)

(defmethod haptic_bridge::StartControlRequest
  (:response () (instance haptic_bridge::StartControlResponse :init)))

(setf (get haptic_bridge::StartControlRequest :md5sum-) "99bedf6bf4f1b97105db84a2d5232627")
(setf (get haptic_bridge::StartControlRequest :datatype-) "haptic_bridge/StartControlRequest")
(setf (get haptic_bridge::StartControlRequest :definition-)
      "bool isControl
---
")

(setf (get haptic_bridge::StartControlResponse :md5sum-) "99bedf6bf4f1b97105db84a2d5232627")
(setf (get haptic_bridge::StartControlResponse :datatype-) "haptic_bridge/StartControlResponse")
(setf (get haptic_bridge::StartControlResponse :definition-)
      "bool isControl
---
")



(provide :haptic_bridge/StartControl "99bedf6bf4f1b97105db84a2d5232627")


