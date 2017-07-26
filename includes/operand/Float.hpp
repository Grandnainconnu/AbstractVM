//
// Float.hpp for Float in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:32:49 2017 Jean Walrave
// Last update Sun Jul 23 14:17:30 2017 Jean Walrave
//

#ifndef __FLOAT_HPP__
# define __FLOAT_HPP__

# include "AbstractOperand.hpp"

class Float : public AbstractOperand<float>
{
public:
  Float(const std::string&);

  IOperand*	operator%(const IOperand&) const;

  ~Float() = default;
};

template<>
int
AbstractOperand<float>::getPrecision() const
{
  return (7);
}

template<>
int
AbstractOperand<float>::getCapacity() const
{
  return (4);
}

template<>
eOperandType
AbstractOperand<float>::getType() const
{
  return (FLOAT);
}

#endif /* !__FLOAT_HHP__ */
