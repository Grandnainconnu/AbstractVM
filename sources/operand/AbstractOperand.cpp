//
// AbstractOperand.cpp for AbstractOperand in /home/jean.walrave/projects/epitech/abstractVM_2016/sources/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:43:23 2017 Jean Walrave
// Last update Mon Jul 24 10:31:55 2017 Jean Walrave
//

#include <sstream>
#include "Exception.hh"
#include "Factory.hpp"
#include "operand/AbstractOperand.hpp"

template<typename T>
AbstractOperand<T>::AbstractOperand(const std::string& value)
  : _value(value)
{
  ;
}

template<typename T>
std::string
AbstractOperand<T>::toString() const
{
  return (this->_value);
}

template<typename T>
IOperand*
AbstractOperand<T>::operator+(const IOperand& rhs) const
{
  T	lCValue;
  T	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue + rCValue)));
}

template<typename T>
IOperand*
AbstractOperand<T>::operator-(const IOperand& rhs) const
{
  T	lCValue;
  T	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue - rCValue)));
}

template<typename T>
IOperand*
AbstractOperand<T>::operator*(const IOperand& rhs) const
{
  T	lCValue;
  T	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  return (Factory::createOperand(this->getType(), std::to_string(lCValue * rCValue)));
}

template<typename T>
IOperand*
AbstractOperand<T>::operator/(const IOperand& rhs) const
{
  T	lCValue;
  T	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Division by 0");

  return (Factory::createOperand(this->getType(), std::to_string(lCValue / rCValue)));
}

template<typename T>
IOperand*
AbstractOperand<T>::operator%(const IOperand& rhs) const
{
  T	lCValue;
  T	rCValue;

  std::istringstream(this->toString()) >> lCValue;
  std::istringstream(rhs.toString()) >> rCValue;

  if (!rCValue)
    throw Exception::OORException("Module by 0");

  return (Factory::createOperand(this->getType(), std::to_string((int)lCValue % (int)rCValue)));
}

template<typename T>
AbstractOperand<T>::~AbstractOperand()
{
  ;
}
