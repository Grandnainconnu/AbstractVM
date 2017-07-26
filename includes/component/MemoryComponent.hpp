//
// MemoryComponent.hpp for MemoryComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 22:10:41 2017 Jean Walrave
// Last update Mon Jul 24 10:45:47 2017 Jean Walrave
//

#ifndef __MEMORY_COMPONENT_HPP__
# define __MEMORY_COMPONENT_HPP__

# include <vector>
# include "operand/IOperand.hpp"

namespace AVMComponent
{
  class MemoryComponent
  {
  private:
    std::vector<IOperand*>	_stack;
  public:
    MemoryComponent();
    MemoryComponent(const MemoryComponent&);

    void	updateAt(std::size_t, IOperand*); 
    void	push(IOperand*);
    void	assert(IOperand*);
    void	pop(void);
    void	clear(void);
    void	dup(void);
    void	swap(void);

    const std::vector<IOperand*>	getStack(void) const;

    ~MemoryComponent();
  };
};

#endif /* !__MEMORY_COMPONENT_HPP__ */
