;; Auto-generated. Do not edit!


(when (boundp 'haptic_bridge::SwitchAxis)
  (if (not (find-package "HAPTIC_BRIDGE"))
    (make-package "HAPTIC_BRIDGE"))
  (shadow 'SwitchAxis (find-package "HAPTIC_BRIDGE")))
(unless (find-package "HAPTIC_BRIDGE::SWITCHAXIS")
  (make-package "HAPTIC_BRIDGE::SWITCHAXIS"))
(unless (find-package "HAPTIC_BRIDGE::SWITCHAXISREQUEST")
  (make-package "HAPTIC_BRIDGE::SWITCHAXISREQUEST"))
(unless (find-package "HAPTIC_BRIDGE::SWITCHAXISRESPONSE")
  (make-package "HAPTIC_BRIDGE::SWITCHAXISRESPONSE"))

(in-package "ROS")





(defclass haptic_bridge::SwitchAxisRequest
  :super ros::object
  :slots (_Axis_X _Axis_Y _Axis_Z _Axis_A _Axis_B _Axis_C ))

(defmethod haptic_bridge::SwitchAxisRequest
  (:init
   (&key
    ((:Axis_X __Axis_X) 0)
    ((:Axis_Y __Axis_Y) 0)
    ((:Axis_Z __Axis_Z) 0)
    ((:Axis_A __Axis_A) 0)
    ((:Axis_B __Axis_B) 0)
    ((:Axis_C __Axis_C) 0)
    )
   (send-super :init)
   (setq _Axis_X (round __Axis_X))
   (setq _Axis_Y (round __Axis_Y))
   (setq _Axis_Z (round __Axis_Z))
   (setq _Axis_A (round __Axis_A))
   (setq _Axis_B (round __Axis_B))
   (setq _Axis_C (round __Axis_C))
   self)
  (:Axis_X
   (&optional __Axis_X)
   (if __Axis_X (setq _Axis_X __Axis_X)) _Axis_X)
  (:Axis_Y
   (&optional __Axis_Y)
   (if __Axis_Y (setq _Axis_Y __Axis_Y)) _Axis_Y)
  (:Axis_Z
   (&optional __Axis_Z)
   (if __Axis_Z (setq _Axis_Z __Axis_Z)) _Axis_Z)
  (:Axis_A
   (&optional __Axis_A)
   (if __Axis_A (setq _Axis_A __Axis_A)) _Axis_A)
  (:Axis_B
   (&optional __Axis_B)
   (if __Axis_B (setq _Axis_B __Axis_B)) _Axis_B)
  (:Axis_C
   (&optional __Axis_C)
   (if __Axis_C (setq _Axis_C __Axis_C)) _Axis_C)
  (:serialization-length
   ()
   (+
    ;; int8 _Axis_X
    1
    ;; int8 _Axis_Y
    1
    ;; int8 _Axis_Z
    1
    ;; int8 _Axis_A
    1
    ;; int8 _Axis_B
    1
    ;; int8 _Axis_C
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _Axis_X
       (write-byte _Axis_X s)
     ;; int8 _Axis_Y
       (write-byte _Axis_Y s)
     ;; int8 _Axis_Z
       (write-byte _Axis_Z s)
     ;; int8 _Axis_A
       (write-byte _Axis_A s)
     ;; int8 _Axis_B
       (write-byte _Axis_B s)
     ;; int8 _Axis_C
       (write-byte _Axis_C s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _Axis_X
     (setq _Axis_X (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_X 127) (setq _Axis_X (- _Axis_X 256)))
   ;; int8 _Axis_Y
     (setq _Axis_Y (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_Y 127) (setq _Axis_Y (- _Axis_Y 256)))
   ;; int8 _Axis_Z
     (setq _Axis_Z (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_Z 127) (setq _Axis_Z (- _Axis_Z 256)))
   ;; int8 _Axis_A
     (setq _Axis_A (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_A 127) (setq _Axis_A (- _Axis_A 256)))
   ;; int8 _Axis_B
     (setq _Axis_B (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_B 127) (setq _Axis_B (- _Axis_B 256)))
   ;; int8 _Axis_C
     (setq _Axis_C (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Axis_C 127) (setq _Axis_C (- _Axis_C 256)))
   ;;
   self)
  )

(defclass haptic_bridge::SwitchAxisResponse
  :super ros::object
  :slots ())

(defmethod haptic_bridge::SwitchAxisResponse
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

(defclass haptic_bridge::SwitchAxis
  :super ros::object
  :slots ())

(setf (get haptic_bridge::SwitchAxis :md5sum-) "d49f586c863effd36097bed82b38127a")
(setf (get haptic_bridge::SwitchAxis :datatype-) "haptic_bridge/SwitchAxis")
(setf (get haptic_bridge::SwitchAxis :request) haptic_bridge::SwitchAxisRequest)
(setf (get haptic_bridge::SwitchAxis :response) haptic_bridge::SwitchAxisResponse)

(defmethod haptic_bridge::SwitchAxisRequest
  (:response () (instance haptic_bridge::SwitchAxisResponse :init)))

(setf (get haptic_bridge::SwitchAxisRequest :md5sum-) "d49f586c863effd36097bed82b38127a")
(setf (get haptic_bridge::SwitchAxisRequest :datatype-) "haptic_bridge/SwitchAxisRequest")
(setf (get haptic_bridge::SwitchAxisRequest :definition-)
      "int8 Axis_X
int8 Axis_Y
int8 Axis_Z
int8 Axis_A
int8 Axis_B
int8 Axis_C
---
")

(setf (get haptic_bridge::SwitchAxisResponse :md5sum-) "d49f586c863effd36097bed82b38127a")
(setf (get haptic_bridge::SwitchAxisResponse :datatype-) "haptic_bridge/SwitchAxisResponse")
(setf (get haptic_bridge::SwitchAxisResponse :definition-)
      "int8 Axis_X
int8 Axis_Y
int8 Axis_Z
int8 Axis_A
int8 Axis_B
int8 Axis_C
---
")



(provide :haptic_bridge/SwitchAxis "d49f586c863effd36097bed82b38127a")


