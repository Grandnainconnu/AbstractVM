//
// Factory.hpp for Factory in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 11:27:24 2017 Jean Walrave
// Last update Fri Jul 21 22:17:24 2017 Jean Walrave
//

#ifndef __FACTORY_HPP__
# define __FACTORY_HPP__

# include <map>
# include "operand/IOperand.hpp"

class Factory
{
private:
  std::map<eOperandType, IOperand* (Factory::*)(const std::string&)>	_operands;

  IOperand*		createInt8(const std::string&);
  IOperand*		createInt16(const std::string&);
  IOperand*		createInt32(const std::string&);
  IOperand*		createFloat(const std::string&);
  IOperand*		createDouble(const std::string&);
  IOperand*		createBigDecimal(const std::string&);
public:
  Factory();
  Factory(const Factory&) = delete;

  const std::map<eOperandType, IOperand* (Factory::*)(const std::string&)>&	getOperands() const;

  static IOperand*	createOperand(eOperandType, const std::string&);

  Factory&		operator=(const Factory&) = delete;

  ~Factory() = default;
};

#endif /* !__FACTORY_HPP__ */
