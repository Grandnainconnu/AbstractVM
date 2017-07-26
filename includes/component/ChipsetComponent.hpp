//
// ChipsetComponent.hpp for ChipsetComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 22:26:39 2017 Jean Walrave
// Last update Tue Jul 25 20:44:33 2017 Jean Walrave
//

#ifndef __CHIPSET_COMPONENT_HPP__
# define __CHIPSET_COMPONENT_HPP__

# include <map>
# include "operand/IOperand.hpp"

namespace AVMComponent
{
  class ChipsetComponent
  {
  private:
    std::map<std::string, eOperandType>	_operandTypes;
  public:
    ChipsetComponent();
    ChipsetComponent(const ChipsetComponent&) = delete;

    IOperand*	createOperand(const std::string&, const std::string&) const;
    IOperand*	createOperand(const eOperandType&, const std::string&) const;

    void	processInstructions(void) const;
    void	dump(const std::vector<IOperand*>&) const;
    void	print(const IOperand*) const;

    const eOperandType&	getOperandType(const std::string&) const;

    ~ChipsetComponent() = default;
  };
};

#endif /* !__CHIPSET_COMPONENT_HPP__ */
