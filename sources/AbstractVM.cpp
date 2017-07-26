//
// AbstractVM.cpp for AbstractVM in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Thu Jul 20 10:52:45 2017 Jean Walrave
// Last update Sun Jul 23 15:47:31 2017 Jean Walrave
//

#include <iostream>
#include "AbstractVM.hpp"
#include "Exception.hh"

AVMComponent::CPUComponent*	AbstractVM::_cpu = new AVMComponent::CPUComponent();
AVMComponent::MemoryComponent*	AbstractVM::_memory = new AVMComponent::MemoryComponent();
AVMComponent::ChipsetComponent*	AbstractVM::_chipset = new AVMComponent::ChipsetComponent();
AVMComponent::IOComponent*	AbstractVM::_io = new AVMComponent::IOComponent();

void
readFromFiles(char **argv)
{
  for (int i = 1; argv[i]; i++)
    {
      std::ifstream	f(argv[i]);

      AbstractVM::getIO()->readInstructions(f, true);
    }
}

bool
AbstractVM::readInstructions(int argc, char **argv)
{
  bool	exception = false;

  try {
    if (argc > 1)
      readFromFiles(argv);
    else
      AbstractVM::getIO()->readInstructions(std::cin);
  } catch (const Exception::IOException& e) {
    exception = true;

    std::cerr << "[IO exception] " << e.what() << std::endl;
  }

  return (exception == false);
}

bool
AbstractVM::run(void)
{
  bool	exception = false;

  try {
    AbstractVM::getChipset()->processInstructions();
  } catch (const Exception::OORException& e) {
    exception = true;

    std::cerr << "[Out of range exception] " << e.what() << std::endl;
  } catch (const Exception::MemoryException& e) {
    exception = true;

    std::cerr << "[Memory exception] " << e.what() << std::endl;
  } catch (const Exception::CPUException& e) {
    exception = true;

    std::cerr << "[CPU exception] " << e.what() << std::endl;
  }

  return (exception == false);
}

AVMComponent::CPUComponent*
AbstractVM::getCPU()
{
  return (AbstractVM::_cpu);
}

AVMComponent::MemoryComponent*
AbstractVM::getMemory()
{
  return (AbstractVM::_memory);
}

AVMComponent::ChipsetComponent*
AbstractVM::getChipset()
{
  return (AbstractVM::_chipset);
}

AVMComponent::IOComponent*
AbstractVM::getIO()
{
  return (AbstractVM::_io);
}

AbstractVM::~AbstractVM()
{
  delete (this->_cpu);
  delete (this->_memory);
  delete (this->_chipset);
  delete (this->_io);
}

int		main(int argc, char **argv)
{
  AbstractVM	vm;

  if (false == vm.readInstructions(argc, argv) || false == vm.run())
    return (84);
  return (0);
}
