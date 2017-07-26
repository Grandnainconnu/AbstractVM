//
// Float.cpp for Float in /home/jean.walrave/projects/epitech/abstractVM_2016/sources/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 13:19:02 2017 Jean Walrave
// Last update Mon Jul 24 18:30:34 2017 Jean Walrave
//

#include <math.h>
#include <sstream>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/Float.hpp"

Float::Float(const std::string& value)
  : AbstractOperand(value)
{
  ;
}

IOperand*
Float::operator%(const IOperand& rhs) const
{
  float	lCValue;
  float	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Module by 0");

  return (Factory::createOperand(this->getType(), std::to_string(fmod(lCValue, rCValue))));
}
