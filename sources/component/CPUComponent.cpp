//
// CPUComponent.cpp for CPUComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Sat Jul 22 11:51:12 2017 Jean Walrave
// Last update Wed Jul 26 11:24:28 2017 Jean Walrave
//

#include <iostream>
#include "AbstractVM.hpp"
#include "Exception.hh"
#include "operand/AbstractOperand.hpp"
#include "component/CPUComponent.hpp"

AVMComponent::CPUComponent::CPUComponent() : _running(true)
{
  for (auto& registerN : this->_register)
    registerN = nullptr;

  this->_oHandlers["push"] = &AVMComponent::CPUComponent::push;
  this->_oHandlers["assert"] = &AVMComponent::CPUComponent::assert;
  this->_oHandlers["store"] = &AVMComponent::CPUComponent::store;
  this->_oHandlers["load"] = &AVMComponent::CPUComponent::load;

  this->_handlers["add"] = &AVMComponent::CPUComponent::add;
  this->_handlers["sub"] = &AVMComponent::CPUComponent::sub;
  this->_handlers["mul"] = &AVMComponent::CPUComponent::mul;
  this->_handlers["div"] = &AVMComponent::CPUComponent::div;
  this->_handlers["mod"] = &AVMComponent::CPUComponent::mod;

  this->_handlers["pop"] = &AVMComponent::CPUComponent::pop;
  this->_handlers["clear"] = &AVMComponent::CPUComponent::clear;
  this->_handlers["dup"] = &AVMComponent::CPUComponent::dup;
  this->_handlers["swap"] = &AVMComponent::CPUComponent::swap;
  this->_handlers["dump"] = &AVMComponent::CPUComponent::dump;
  this->_handlers["print"] = &AVMComponent::CPUComponent::print;
  this->_handlers["exit"] = &AVMComponent::CPUComponent::exit;
}

bool
AVMComponent::CPUComponent::isRunning() const
{
  return (this->_running);
}

void
AVMComponent::CPUComponent::processInstruction(const std::string& instruction, IOperand* operand)
{
  if (nullptr != operand)
    ((this)->*(this->_oHandlers.at(instruction)))(operand);
  else
    ((this)->*(this->_handlers.at(instruction)))();
}

void
AVMComponent::CPUComponent::pop()
{
  AbstractVM::getMemory()->pop();
}

void
AVMComponent::CPUComponent::clear()
{
  AbstractVM::getMemory()->clear();
}

void
AVMComponent::CPUComponent::dup()
{
  AbstractVM::getMemory()->dup();
}

void
AVMComponent::CPUComponent::swap()
{
  AbstractVM::getMemory()->swap();
}

void
AVMComponent::CPUComponent::dump()
{
  AbstractVM::getChipset()->dump(AbstractVM::getMemory()->getStack());
}

void
AVMComponent::CPUComponent::print()
{
  IOperand*	front = AbstractVM::getMemory()->getStack().front();

  if (front->getType() != INT8)
    throw Exception::CPUException("Top of the stack is not of type <Int8>");

  AbstractVM::getChipset()->print(front);
}

void
AVMComponent::CPUComponent::push(IOperand* operand)
{
  AbstractVM::getMemory()->push(operand);
}

void
AVMComponent::CPUComponent::assert(IOperand* operand)
{
  AbstractVM::getMemory()->assert(operand);
}

void
AVMComponent::CPUComponent::store(IOperand* operand)
{
  short	registerN;

  std::istringstream(operand->toString()) >> registerN;

  if (registerN > 15 or registerN < 0 or AbstractVM::getMemory()->getStack().empty())
    throw Exception::CPUException("Can't proceed store instruction.");
  this->_register[registerN] = this->makeCopy(AbstractVM::getMemory()->getStack().front());

  AbstractVM::getMemory()->pop();

  delete (operand);
}

void
AVMComponent::CPUComponent::load(IOperand* operand)
{
  short registerN;

  std::istringstream(operand->toString()) >> registerN;

  if (!(registerN > 15 or registerN < 0 or this->_register[registerN] == nullptr))
    this->push(this->makeCopy(this->_register[registerN]));

  delete (operand);
}

const std::pair<const IOperand*, const IOperand*>
AVMComponent::CPUComponent::prepareOperation() const
{
  std::pair<const IOperand*, const IOperand*>	operands = {nullptr, nullptr};
  auto	stack = AbstractVM::getMemory()->getStack();

  if (2 <= AbstractVM::getMemory()->getStack().size())
    {
      operands.first = *(AbstractVM::getMemory()->getStack().begin() + 1);
      operands.second = AbstractVM::getMemory()->getStack().front();

      if (operands.second->getCapacity() > operands.first->getCapacity() || operands.second->getPrecision() > operands.first->getPrecision())
	{
	  IOperand*	nloperand = AbstractVM::getChipset()->createOperand(operands.second->getType(), operands.first->toString());

	  AbstractVM::getMemory()->updateAt(1, nloperand);

	  operands.first = nloperand;
	}
    }

  return (operands);
}

void
AVMComponent::CPUComponent::add()
{
  auto		operands = this->prepareOperation();
  IOperand*	r;

  if (operands.first == nullptr)
    throw Exception::CPUException("Can't proceed addition, not enough operand.");

   r = *(operands.first) + *(operands.second);

  AbstractVM::getMemory()->pop();
  AbstractVM::getMemory()->pop();

  this->push(r);
}

void
AVMComponent::CPUComponent::sub()
{
    auto		operands = this->prepareOperation();
  IOperand*	r;

  if (operands.first == nullptr)
    throw Exception::CPUException("Can't proceed subtraction, not enough operand.");

   r = *(operands.first) - *(operands.second);

  AbstractVM::getMemory()->pop();
  AbstractVM::getMemory()->pop();

  this->push(r);
}

void
AVMComponent::CPUComponent::mul()
{
    auto		operands = this->prepareOperation();
  IOperand*	r;

  if (operands.first == nullptr)
    throw Exception::CPUException("Can't proceed multiplication, not enough operand.");

   r = *(operands.first) * *(operands.second);

  AbstractVM::getMemory()->pop();
  AbstractVM::getMemory()->pop();

  this->push(r);
}

void
AVMComponent::CPUComponent::div()
{
  auto		operands = this->prepareOperation();
  IOperand*	r;

  if (operands.first == nullptr)
    throw Exception::CPUException("Can't proceed division, not enough operand.");

   r = *(operands.first) / *(operands.second);

  AbstractVM::getMemory()->pop();
  AbstractVM::getMemory()->pop();

  this->push(r);
}

void
AVMComponent::CPUComponent::mod()
{
  auto		operands = this->prepareOperation();
  IOperand*	r;

  if (operands.first == nullptr)
    throw Exception::CPUException("Can't proceed modulo, not enough operand.");

   r = *(operands.first) % *(operands.second);

  AbstractVM::getMemory()->pop();
  AbstractVM::getMemory()->pop();

  this->push(r);
}

void
AVMComponent::CPUComponent::exit()
{
  this->_running = false;
}

IOperand*
AVMComponent::CPUComponent::makeCopy(IOperand* operand) const
{
  return (AbstractVM::getChipset()->createOperand(operand->getType(), operand->toString()));
}

AVMComponent::CPUComponent::~CPUComponent()
{
  for (auto& registerN : this->_register)
    if (registerN != nullptr)
      delete (registerN);
}
