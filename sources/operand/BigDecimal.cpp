//
// BigDecimal.cpp for BigDecimal in /home/jean.walrave/projects/epitech/abstractVM_2016/sources/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 13:19:50 2017 Jean Walrave
// Last update Mon Jul 24 18:32:21 2017 Jean Walrave
//

#include <math.h>
#include <sstream>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/BigDecimal.hpp"

BigDecimal::BigDecimal(const std::string& value)
  : AbstractOperand(value)
{
  ;
}

IOperand*
BigDecimal::operator%(const IOperand& rhs) const
{
  long double	lCValue;
  long double	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Modulo by 0");

  return (Factory::createOperand(this->getType(), std::to_string(fmod(lCValue, rCValue))));
}
