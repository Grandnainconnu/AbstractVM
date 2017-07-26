//
// ChipsetComponent.cpp for ChipsetComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Sat Jul 22 12:02:30 2017 Jean Walrave
// Last update Tue Jul 25 20:46:08 2017 Jean Walrave
//

#include "Factory.hpp"
#include "AbstractVM.hpp"
#include "component/ChipsetComponent.hpp"

AVMComponent::ChipsetComponent::ChipsetComponent()
{
  this->_operandTypes["int8"] = INT8;
  this->_operandTypes["int16"] = INT16;
  this->_operandTypes["int32"] = INT32;
  this->_operandTypes["float"] = FLOAT;
  this->_operandTypes["double"] = DOUBLE;
  this->_operandTypes["bigdecimal"] = BIGDECIMAL;
}

IOperand*
AVMComponent::ChipsetComponent::createOperand(const std::string& operandType, const std::string& operand) const
{
  return (Factory::createOperand(this->getOperandType(operandType), operand));
}

IOperand*
AVMComponent::ChipsetComponent::createOperand(const eOperandType& operandType, const std::string& operand) const
{
  return (Factory::createOperand(operandType, operand));
}

const eOperandType&
AVMComponent::ChipsetComponent::getOperandType(const std::string& operandType) const
{
  return (this->_operandTypes.at(operandType));
}

void
AVMComponent::ChipsetComponent::dump(const std::vector<IOperand*>& operands) const
{
  AbstractVM::getIO()->dump(operands);
}

void
AVMComponent::ChipsetComponent::print(const IOperand* operand) const
{
  AbstractVM::getIO()->print(operand);
}

void
AVMComponent::ChipsetComponent::processInstructions(void) const
{
  for (auto& instruction : AbstractVM::getIO()->getInstructions())
    {
      if (false == AbstractVM::getCPU()->isRunning())
	break;

      IOperand*	operand = nullptr;

      if (false == instruction.second.empty())
	operand = createOperand(instruction.second.front(), instruction.second.back());

      AbstractVM::getCPU()->processInstruction(instruction.first, operand);
    }
}
