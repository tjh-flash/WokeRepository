// Auto-generated. Do not edit!

// (in-package haptic_bridge.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SwitchAxisRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Axis_X = null;
      this.Axis_Y = null;
      this.Axis_Z = null;
      this.Axis_A = null;
      this.Axis_B = null;
      this.Axis_C = null;
    }
    else {
      if (initObj.hasOwnProperty('Axis_X')) {
        this.Axis_X = initObj.Axis_X
      }
      else {
        this.Axis_X = 0;
      }
      if (initObj.hasOwnProperty('Axis_Y')) {
        this.Axis_Y = initObj.Axis_Y
      }
      else {
        this.Axis_Y = 0;
      }
      if (initObj.hasOwnProperty('Axis_Z')) {
        this.Axis_Z = initObj.Axis_Z
      }
      else {
        this.Axis_Z = 0;
      }
      if (initObj.hasOwnProperty('Axis_A')) {
        this.Axis_A = initObj.Axis_A
      }
      else {
        this.Axis_A = 0;
      }
      if (initObj.hasOwnProperty('Axis_B')) {
        this.Axis_B = initObj.Axis_B
      }
      else {
        this.Axis_B = 0;
      }
      if (initObj.hasOwnProperty('Axis_C')) {
        this.Axis_C = initObj.Axis_C
      }
      else {
        this.Axis_C = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SwitchAxisRequest
    // Serialize message field [Axis_X]
    bufferOffset = _serializer.int8(obj.Axis_X, buffer, bufferOffset);
    // Serialize message field [Axis_Y]
    bufferOffset = _serializer.int8(obj.Axis_Y, buffer, bufferOffset);
    // Serialize message field [Axis_Z]
    bufferOffset = _serializer.int8(obj.Axis_Z, buffer, bufferOffset);
    // Serialize message field [Axis_A]
    bufferOffset = _serializer.int8(obj.Axis_A, buffer, bufferOffset);
    // Serialize message field [Axis_B]
    bufferOffset = _serializer.int8(obj.Axis_B, buffer, bufferOffset);
    // Serialize message field [Axis_C]
    bufferOffset = _serializer.int8(obj.Axis_C, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SwitchAxisRequest
    let len;
    let data = new SwitchAxisRequest(null);
    // Deserialize message field [Axis_X]
    data.Axis_X = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [Axis_Y]
    data.Axis_Y = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [Axis_Z]
    data.Axis_Z = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [Axis_A]
    data.Axis_A = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [Axis_B]
    data.Axis_B = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [Axis_C]
    data.Axis_C = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a service object
    return 'haptic_bridge/SwitchAxisRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd49f586c863effd36097bed82b38127a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 Axis_X
    int8 Axis_Y
    int8 Axis_Z
    int8 Axis_A
    int8 Axis_B
    int8 Axis_C
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SwitchAxisRequest(null);
    if (msg.Axis_X !== undefined) {
      resolved.Axis_X = msg.Axis_X;
    }
    else {
      resolved.Axis_X = 0
    }

    if (msg.Axis_Y !== undefined) {
      resolved.Axis_Y = msg.Axis_Y;
    }
    else {
      resolved.Axis_Y = 0
    }

    if (msg.Axis_Z !== undefined) {
      resolved.Axis_Z = msg.Axis_Z;
    }
    else {
      resolved.Axis_Z = 0
    }

    if (msg.Axis_A !== undefined) {
      resolved.Axis_A = msg.Axis_A;
    }
    else {
      resolved.Axis_A = 0
    }

    if (msg.Axis_B !== undefined) {
      resolved.Axis_B = msg.Axis_B;
    }
    else {
      resolved.Axis_B = 0
    }

    if (msg.Axis_C !== undefined) {
      resolved.Axis_C = msg.Axis_C;
    }
    else {
      resolved.Axis_C = 0
    }

    return resolved;
    }
};

class SwitchAxisResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SwitchAxisResponse
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SwitchAxisResponse
    let len;
    let data = new SwitchAxisResponse(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'haptic_bridge/SwitchAxisResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SwitchAxisResponse(null);
    return resolved;
    }
};

module.exports = {
  Request: SwitchAxisRequest,
  Response: SwitchAxisResponse,
  md5sum() { return 'd49f586c863effd36097bed82b38127a'; },
  datatype() { return 'haptic_bridge/SwitchAxis'; }
};
