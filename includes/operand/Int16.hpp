//
// Int16.hpp for Int16 in /home/jean.walrave/projects/epitech/abstractVM_2016/includes/operand
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 12:32:49 2017 Jean Walrave
// Last update Sun Jul 23 14:16:37 2017 Jean Walrave
//

#ifndef __INT16_HPP__
# define __INT16_HPP__

# include "AbstractOperand.hpp"

class Int16 : public AbstractOperand<int16_t>
{
public:
  Int16(const std::string&);
  ~Int16() = default;
};

template<>
int
AbstractOperand<int16_t>::getPrecision() const
{
  return (0);
}

template<>
int
AbstractOperand<int16_t>::getCapacity() const
{
  return (2);
}

template<>
eOperandType
AbstractOperand<int16_t>::getType() const
{
  return (INT16);
}

#endif /* !__INT16_HHP__ */
