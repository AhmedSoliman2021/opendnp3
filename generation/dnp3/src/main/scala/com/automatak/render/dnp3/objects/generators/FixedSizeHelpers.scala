package com.automatak.render.dnp3.objects.generators

import com.automatak.render.EnumModel
import com.automatak.render.cpp._
import com.automatak.render.dnp3.objects._

object FixedSizeHelpers {

  def getCppFieldType(x: FixedSizeFieldType): String = x match {
    case UInt8Field => "uint8_t"
    case UInt16Field => "uint16_t"
    case UInt32Field => "uint32_t"
    case UInt48Field => "DNPTime"
    case SInt16Field => "int16_t"
    case SInt32Field => "int32_t"
    case Float32Field => "float"
    case Float64Field => "double"
    case EnumFieldType(model: EnumModel) => model.name
  }

  def getCppFieldTypeParser(x: FixedSizeFieldType): String = x match {
    case UInt8Field => "UInt8"
    case UInt16Field => "UInt16"
    case UInt32Field => "UInt32"
    case UInt48Field => "UInt48"
    case SInt16Field => "Int16"
    case SInt32Field => "Int32"
    case Float32Field => "SingleFloat"
    case Float64Field => "DoubleFloat"
    case EnumFieldType(model: EnumModel) => model.name
  }

  // Any special headers required for fixed-size fields
  def fieldHeaders(fields: List[FixedSizeField]): List[String] = fields.map { f =>
     f.typ match {
       case ef : EnumFieldType => List(quoted("opendnp3/gen/%s.h".format(ef.model.name)))
       case _ => Nil
     }
  }.flatten


}
