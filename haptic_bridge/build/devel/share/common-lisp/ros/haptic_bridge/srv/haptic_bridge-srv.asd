
(cl:in-package :asdf)

(defsystem "haptic_bridge-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "CloseDevice" :depends-on ("_package_CloseDevice"))
    (:file "_package_CloseDevice" :depends-on ("_package"))
    (:file "OpenDevice" :depends-on ("_package_OpenDevice"))
    (:file "_package_OpenDevice" :depends-on ("_package"))
    (:file "StartControl" :depends-on ("_package_StartControl"))
    (:file "_package_StartControl" :depends-on ("_package"))
    (:file "SwitchAxis" :depends-on ("_package_SwitchAxis"))
    (:file "_package_SwitchAxis" :depends-on ("_package"))
  ))