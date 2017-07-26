//
// MemoryComponent.cpp for MemoryComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Sat Jul 22 11:56:56 2017 Jean Walrave
// Last update Mon Jul 24 10:45:30 2017 Jean Walrave
//

#include <algorithm>
#include "AbstractVM.hpp"
#include "Exception.hh"
#include "component/MemoryComponent.hpp"

AVMComponent::MemoryComponent::MemoryComponent()
{
  ;
}

AVMComponent::MemoryComponent::MemoryComponent(const AVMComponent::MemoryComponent& memory)
{
  this->_stack = memory.getStack();
}

void
AVMComponent::MemoryComponent::updateAt(std::size_t index, IOperand* operand)
{
  if (this->_stack.at(index))
    delete (this->_stack.at(index));

  this->_stack.at(index) = operand;
}

void
AVMComponent::MemoryComponent::push(IOperand* operand)
{
  this->_stack.insert(this->_stack.begin(), operand);
}

void
AVMComponent::MemoryComponent::pop()
{
  if (!this->_stack.empty())
    {
      if (this->_stack.front() != nullptr)
	delete (this->_stack.front());

      this->_stack.erase(this->_stack.begin());
    }
  else
    throw Exception::MemoryException("Try to 'pop' on empty stack.");
}

void
AVMComponent::MemoryComponent::clear()
{
  this->_stack.clear();
}

void
AVMComponent::MemoryComponent::dup()
{
  this->push(AbstractVM::getCPU()->makeCopy(this->_stack.front()));
}

void
AVMComponent::MemoryComponent::swap()
{
  if (2 <= this->_stack.size())
    std::iter_swap(this->_stack.begin(), this->_stack.begin() + 1);
  else
    throw Exception::MemoryException("Try to 'swap' on empty stack.");
}

void
AVMComponent::MemoryComponent::assert(IOperand* operand)
{
  IOperand*	front = this->_stack.front();

  if (front->getType() != operand->getType() or front->toString() != operand->toString())
    throw Exception::MemoryException("Assertion error");

  delete (operand);
}

const std::vector<IOperand*>
AVMComponent::MemoryComponent::getStack() const
{
  return (this->_stack);
}

AVMComponent::MemoryComponent::~MemoryComponent()
{
  for (auto& operand : this->_stack)
    delete (operand);
}
