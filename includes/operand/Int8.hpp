//
// Int8.hpp for Int8 in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:32:49 2017 Jean Walrave
// Last update Sun Jul 23 14:38:18 2017 Jean Walrave
//

#ifndef __INT8_HPP__
# define __INT8_HPP__

# include "AbstractOperand.hpp"

class Int8 : public AbstractOperand<int8_t>
{
public:
  Int8(const std::string&);

  IOperand*	operator+(const IOperand&) const;
  IOperand*	operator-(const IOperand&) const;
  IOperand*	operator*(const IOperand&) const;
  IOperand*	operator/(const IOperand&) const;
  IOperand*	operator%(const IOperand&) const;

  ~Int8() = default;
};

template<>
int
AbstractOperand<int8_t>::getPrecision() const
{
  return (0);
}

template<>
int
AbstractOperand<int8_t>::getCapacity() const
{
  return (0);
}

template<>
eOperandType
AbstractOperand<int8_t>::getType() const
{
  return (INT8);
}

#endif /* !__INT8_HHP__ */
