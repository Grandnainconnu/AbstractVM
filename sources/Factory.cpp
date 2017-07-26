//
// Factory.cpp for Factory in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 15:43:28 2017 Jean Walrave
// Last update Mon Jul 24 18:35:38 2017 Jean Walrave
//

#include <memory>
#include <sstream>
#include <stdexcept>
#include <limits>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/Int8.hpp"
#include "operand/Int16.hpp"
#include "operand/Int32.hpp"
#include "operand/Float.hpp"
#include "operand/Double.hpp"
#include "operand/BigDecimal.hpp"

Factory::Factory()
{
  this->_operands[INT8] = &Factory::createInt8;
  this->_operands[INT16] = &Factory::createInt16;
  this->_operands[INT32] = &Factory::createInt32;
  this->_operands[FLOAT] = &Factory::createFloat;
  this->_operands[DOUBLE] = &Factory::createDouble;
  this->_operands[BIGDECIMAL] = &Factory::createBigDecimal;
}

IOperand*
Factory::createOperand(eOperandType type, const std::string& value)
{
  static std::unique_ptr<Factory>	factory(new Factory);

  return ((*factory.*(factory->getOperands().at(type)))(value));
}

const std::map<eOperandType, IOperand* (Factory::*)(const std::string&)>&
Factory::getOperands() const
{
  return (this->_operands);
}

IOperand*
Factory::createInt8(const std::string& value)
{
  short	cValue;

  std::istringstream(value) >> cValue;

  if (cValue <= std::numeric_limits<int8_t>::min() || cValue >= std::numeric_limits<int8_t>::max())
    throw Exception::OORException("Out of range exception for value <Int8, " + value  + ">");

  return (new Int8(value));
}

IOperand*
Factory::createInt16(const std::string& value)
{
  int16_t	cValue;

  std::istringstream(value) >> cValue;

  if (cValue <= std::numeric_limits<int16_t>::min() || cValue >= std::numeric_limits<int16_t>::max())
    throw Exception::OORException("Out of range exception for value <Int16, " + value  + ">");

  return (new Int16(value));
}

IOperand*
Factory::createInt32(const std::string& value)
{
  int32_t	cValue;

  std::istringstream(value) >> cValue;

  if (cValue <= std::numeric_limits<int32_t>::min() || cValue >= std::numeric_limits<int32_t>::max())
    throw Exception::OORException("Out of range exception for value <Int32, " + value  + ">");
 
  return (new Int32(value));
}

IOperand*
Factory::createFloat(const std::string& value)
{
  float		cValue;

  std::istringstream(value) >> cValue;

  if (cValue <= std::numeric_limits<float>::min() || cValue >= std::numeric_limits<float>::max())
    throw Exception::OORException("Out of range exception for value <Float, " + value  + ">");

  return (new Float(value));
}

IOperand*
Factory::createDouble(const std::string& value)
{
  double	cValue;

  try {
    cValue = std::stod(value);
  }
  catch (const std::out_of_range&) {
    throw Exception::OORException("Out of range exception for value <Double, " + value  + ">");
  }

  return (new Double(value));
}

IOperand*
Factory::createBigDecimal(const std::string& value)
{
  long double	cValue;

  try {
    cValue = std::stold(value);
  }
  catch (const std::out_of_range&) {
    throw Exception::OORException("Out of range exception for value <BigDecimal, " + value  + ">");
  }

  return (new BigDecimal(value));
}
