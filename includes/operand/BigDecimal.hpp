//
// BigDecimal.hpp for BigDecimal in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 13:15:26 2017 Jean Walrave
// Last update Mon Jul 24 18:32:43 2017 Jean Walrave
//

#ifndef __BIG_DECIMAL_HPP__
# define __BIG_DECIMAL_HPP__

# include "AbstractOperand.hpp"

class BigDecimal : public AbstractOperand<long double>
{
public:
  BigDecimal(const std::string&);

  IOperand*	operator%(const IOperand&) const;

  ~BigDecimal() = default;
};

template<>
int
AbstractOperand<long double>::getPrecision() const
{
  return (200);
}

template<>
int
AbstractOperand<long double>::getCapacity() const
{
  return (6);
}

template<>
eOperandType
AbstractOperand<long double>::getType() const
{
  return (BIGDECIMAL);
}

#endif /* !__INT8_HHP__ */
