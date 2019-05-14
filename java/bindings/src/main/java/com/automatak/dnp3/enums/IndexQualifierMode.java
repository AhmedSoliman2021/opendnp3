//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

package com.automatak.dnp3.enums;
/**
* Specifies whether opendnp3 optimizes for 1-byte indexes when making requests
*/
public enum IndexQualifierMode
{
  /**
  * Use a one byte qualifier if possible
  */
  allow_one_byte(0x0),
  /**
  * Always use two byte qualifiers even if the index is {@literal <=} 255
  */
  always_two_bytes(0x1);

  private final int id;

  public int toType()
  {
    return id;
  }

  IndexQualifierMode(int id)
  {
    this.id = id;
  }

  public static IndexQualifierMode fromType(int arg)
  {
    switch(arg)
    {
      case(0x0):
        return allow_one_byte;
      case(0x1):
        return always_two_bytes;
      default:
        return allow_one_byte;
    }
  }
}
