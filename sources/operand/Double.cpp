//
// Double.cpp for Double in /home/jean.walrave/projects/epitech/abstractVM_2016/sources/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 13:19:25 2017 Jean Walrave
// Last update Mon Jul 24 18:29:55 2017 Jean Walrave
//

#include <math.h>
#include <sstream>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/Double.hpp"

Double::Double(const std::string& value)
  : AbstractOperand(value)
{
  ;
}

IOperand*
Double::operator%(const IOperand& rhs) const
{
  double	lCValue;
  double	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Modulo by 0");

  return (Factory::createOperand(this->getType(), std::to_string(fmod(lCValue, rCValue))));
}
