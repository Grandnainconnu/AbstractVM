//
// Double.hpp for Double in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:32:49 2017 Jean Walrave
// Last update Sun Jul 23 14:17:59 2017 Jean Walrave
//

#ifndef __DOUBLE_HPP__
# define __DOUBLE_HPP__

# include "AbstractOperand.hpp"

class Double : public AbstractOperand<double>
{
public:
  Double(const std::string&);

  IOperand*	operator%(const IOperand&) const;

  ~Double() = default;
};

template<>
int
AbstractOperand<double>::getPrecision() const
{
  return (15);
}

template<>
int
AbstractOperand<double>::getCapacity() const
{
  return (5);
}

template<>
eOperandType
AbstractOperand<double>::getType() const
{
  return (DOUBLE);
}

#endif /* !__DOUBLE_HHP__ */
