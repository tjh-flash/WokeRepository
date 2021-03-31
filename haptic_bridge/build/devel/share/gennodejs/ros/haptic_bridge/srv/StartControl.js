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

class StartControlRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isControl = null;
    }
    else {
      if (initObj.hasOwnProperty('isControl')) {
        this.isControl = initObj.isControl
      }
      else {
        this.isControl = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type StartControlRequest
    // Serialize message field [isControl]
    bufferOffset = _serializer.bool(obj.isControl, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type StartControlRequest
    let len;
    let data = new StartControlRequest(null);
    // Deserialize message field [isControl]
    data.isControl = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'haptic_bridge/StartControlRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '99bedf6bf4f1b97105db84a2d5232627';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool isControl
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new StartControlRequest(null);
    if (msg.isControl !== undefined) {
      resolved.isControl = msg.isControl;
    }
    else {
      resolved.isControl = false
    }

    return resolved;
    }
};

class StartControlResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type StartControlResponse
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type StartControlResponse
    let len;
    let data = new StartControlResponse(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'haptic_bridge/StartControlResponse';
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
    const resolved = new StartControlResponse(null);
    return resolved;
    }
};

module.exports = {
  Request: StartControlRequest,
  Response: StartControlResponse,
  md5sum() { return '99bedf6bf4f1b97105db84a2d5232627'; },
  datatype() { return 'haptic_bridge/StartControl'; }
};
