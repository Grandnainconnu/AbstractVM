//
// Int32.hpp for Int32 in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:32:49 2017 Jean Walrave
// Last update Sun Jul 23 14:17:09 2017 Jean Walrave
//

#ifndef __INT32_HPP__
# define __INT32_HPP__

# include "AbstractOperand.hpp"

class Int32 : public AbstractOperand<int32_t>
{
public:
  Int32(const std::string&);
  ~Int32() = default;
};

template<>
int
AbstractOperand<int32_t>::getPrecision() const
{
  return (0);
}

template<>
int
AbstractOperand<int32_t>::getCapacity() const
{
  return (3);
}

template<>
eOperandType
AbstractOperand<int32_t>::getType() const
{
  return (INT32);
}

#endif /* !__INT32_HHP__ */
