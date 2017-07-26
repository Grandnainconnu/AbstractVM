//
// AbstractOperand.hpp for Abstract operand in /home/jean.walrave/projects/epitech/abstractVM_2016/includes
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 11:30:41 2017 Jean Walrave
// Last update Mon Jul 24 18:32:01 2017 Jean Walrave
//

#ifndef __ABSTRACT_OPERAND_HPP__
# define __ABSTRACT_OPERAND_HPP__

# include "IOperand.hpp"

template<typename T>
class AbstractOperand : public IOperand
{
protected:
  std::string		_value;
public:
  AbstractOperand(const std::string&);

  virtual std::string	toString() const;

  virtual int		getPrecision() const;
  virtual int		getCapacity() const;
  virtual eOperandType	getType() const;

  virtual IOperand*	operator+(const IOperand&) const;
  virtual IOperand*	operator-(const IOperand&) const;
  virtual IOperand*	operator*(const IOperand&) const;
  virtual IOperand*	operator/(const IOperand&) const;
  virtual IOperand*	operator%(const IOperand&) const;

  ~AbstractOperand();
};

/*
** Int8 instantiation
*/
template class AbstractOperand<int8_t>;

/*
** Int16 instantiation
*/
template class AbstractOperand<int16_t>;

/*
** Int32 instantiation
*/
template class AbstractOperand<int32_t>;

/*
** Float instantiation
*/
template class AbstractOperand<float>;

/*
** Double instantiation
*/
template class AbstractOperand<double>;

/*
** BigDecimal instantiation
*/
template class AbstractOperand<long double>;

#endif /* !__ABSTRACT_OPERAND_HPP__ */
