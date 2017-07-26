//
// AbstractVM.hpp for AbstractVM in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Sat Jul 22 10:20:35 2017 Jean Walrave
// Last update Tue Jul 25 18:21:46 2017 Jean Walrave
//

#ifndef __ABSTRACT_VM_HPP__
# define __ABSTRACT_VM_HPP__

# include "component/CPUComponent.hpp"
# include "component/MemoryComponent.hpp"
# include "component/ChipsetComponent.hpp"
# include "component/IOComponent.hpp"

class AbstractVM
{
private:
  static AVMComponent::CPUComponent*		_cpu;
  static AVMComponent::MemoryComponent*		_memory;
  static AVMComponent::ChipsetComponent*	_chipset;
  static AVMComponent::IOComponent*		_io;
public:
  AbstractVM() = default;

  static AVMComponent::CPUComponent*		getCPU();
  static AVMComponent::MemoryComponent*		getMemory();
  static AVMComponent::ChipsetComponent*	getChipset();
  static AVMComponent::IOComponent*		getIO();

  bool	readInstructions(int, char **);
  bool	run();

  ~AbstractVM();
};

#endif /* !__ABSTRACT_VM_HPP__ */
