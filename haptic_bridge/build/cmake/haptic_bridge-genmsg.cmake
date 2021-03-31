# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "haptic_bridge: 0 messages, 4 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(haptic_bridge_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_custom_target(_haptic_bridge_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "haptic_bridge" "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" ""
)

get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_custom_target(_haptic_bridge_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "haptic_bridge" "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" ""
)

get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_custom_target(_haptic_bridge_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "haptic_bridge" "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" ""
)

get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_custom_target(_haptic_bridge_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "haptic_bridge" "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_cpp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_cpp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_cpp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
)

### Generating Module File
_generate_module_cpp(haptic_bridge
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(haptic_bridge_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(haptic_bridge_generate_messages haptic_bridge_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_cpp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_cpp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_cpp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_cpp _haptic_bridge_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(haptic_bridge_gencpp)
add_dependencies(haptic_bridge_gencpp haptic_bridge_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS haptic_bridge_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
)
_generate_srv_eus(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
)
_generate_srv_eus(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
)
_generate_srv_eus(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
)

### Generating Module File
_generate_module_eus(haptic_bridge
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(haptic_bridge_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(haptic_bridge_generate_messages haptic_bridge_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_eus _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_eus _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_eus _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_eus _haptic_bridge_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(haptic_bridge_geneus)
add_dependencies(haptic_bridge_geneus haptic_bridge_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS haptic_bridge_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_lisp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_lisp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
)
_generate_srv_lisp(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
)

### Generating Module File
_generate_module_lisp(haptic_bridge
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(haptic_bridge_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(haptic_bridge_generate_messages haptic_bridge_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_lisp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_lisp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_lisp _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_lisp _haptic_bridge_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(haptic_bridge_genlisp)
add_dependencies(haptic_bridge_genlisp haptic_bridge_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS haptic_bridge_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
)
_generate_srv_nodejs(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
)
_generate_srv_nodejs(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
)
_generate_srv_nodejs(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
)

### Generating Module File
_generate_module_nodejs(haptic_bridge
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(haptic_bridge_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(haptic_bridge_generate_messages haptic_bridge_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_nodejs _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_nodejs _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_nodejs _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_nodejs _haptic_bridge_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(haptic_bridge_gennodejs)
add_dependencies(haptic_bridge_gennodejs haptic_bridge_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS haptic_bridge_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
)
_generate_srv_py(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
)
_generate_srv_py(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
)
_generate_srv_py(haptic_bridge
  "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
)

### Generating Module File
_generate_module_py(haptic_bridge
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(haptic_bridge_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(haptic_bridge_generate_messages haptic_bridge_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/StartControl.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_py _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/CloseDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_py _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/OpenDevice.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_py _haptic_bridge_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fshs/catkin_ws/src/haptic_bridge/srv/SwitchAxis.srv" NAME_WE)
add_dependencies(haptic_bridge_generate_messages_py _haptic_bridge_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(haptic_bridge_genpy)
add_dependencies(haptic_bridge_genpy haptic_bridge_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS haptic_bridge_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/haptic_bridge
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(haptic_bridge_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/haptic_bridge
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(haptic_bridge_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/haptic_bridge
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(haptic_bridge_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/haptic_bridge
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(haptic_bridge_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/haptic_bridge
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(haptic_bridge_generate_messages_py std_msgs_generate_messages_py)
endif()
