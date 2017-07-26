//
// Int8.cpp for Int8 in /home/jean.walrave/projects/epitech/abstractVM_2016/sources
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:41:52 2017 Jean Walrave
// Last update Sun Jul 23 15:05:37 2017 Jean Walrave
//

#include <sstream>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/Int8.hpp"

Int8::Int8(const std::string& value)
  : AbstractOperand(value)
{
  ;
}

IOperand*
Int8::operator+(const IOperand& rhs) const
{
  short		lCValue;
  short		rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue + rCValue)));
}

IOperand*
Int8::operator-(const IOperand& rhs) const
{
  short		lCValue;
  short		rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue - rCValue)));
}

IOperand*
Int8::operator*(const IOperand& rhs) const
{
  short		lCValue;
  short		rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue * rCValue)));
}

IOperand*
Int8::operator/(const IOperand& rhs) const
{
  short		lCValue;
  short		rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Division by 0");

  return (Factory::createOperand(this->getType(), std::to_string(lCValue / rCValue)));
}

IOperand*
Int8::operator%(const IOperand& rhs) const
{
  short		lCValue;
  short		rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Modulo by 0");

  return (Factory::createOperand(this->getType(), std::to_string(lCValue % rCValue)));
}
