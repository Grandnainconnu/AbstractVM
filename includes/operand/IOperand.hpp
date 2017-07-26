//
// IOperand.hpp for IOperand in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 11:28:11 2017 Jean Walrave
// Last update Sun Jul 23 14:19:21 2017 Jean Walrave
//

#ifndef __IOPERAND_HPP__
# define __IOPERAND_HPP__

# include <string>

enum	eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL
  };

class IOperand
{
public:
  virtual std::string	toString() const = 0;

  virtual int		getPrecision() const = 0;
  virtual int		getCapacity() const = 0;
  virtual eOperandType	getType() const = 0;

  virtual IOperand*	operator+(const IOperand&) const = 0;
  virtual IOperand*	operator-(const IOperand&) const = 0;
  virtual IOperand*	operator*(const IOperand&) const = 0;
  virtual IOperand*	operator/(const IOperand&) const = 0;
  virtual IOperand*	operator%(const IOperand&) const = 0;

  virtual ~IOperand() {}
};

#endif /* !__IOPERAND_HPP__ */
