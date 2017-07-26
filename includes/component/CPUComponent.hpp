//
// CPUComponent.hpp for CPUComponent in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 22:18:51 2017 Jean Walrave
// Last update Tue Jul 25 18:12:00 2017 Jean Walrave
//

#ifndef __CPU_COMPONENT_HPP__
# define __CPU_COMPONENT_HPP__

# include <vector>
# include <map>
# include "operand/IOperand.hpp"

namespace AVMComponent
{
  class CPUComponent
  {
  protected:
    IOperand*							_register[16];
  private:
    bool							_running;
    std::map<std::string, void (CPUComponent::*)(void)>		_handlers;
    std::map<std::string, void (CPUComponent::*)(IOperand*)>	_oHandlers;
  public:
    CPUComponent();
    CPUComponent(const CPUComponent&) = delete;

    bool	isRunning(void) const;

    IOperand*	makeCopy(IOperand*) const;
    void	processInstruction(const std::string&, IOperand*);
    const std::pair<const IOperand*, const IOperand*>	prepareOperation(void) const;

    void	push(IOperand*);
    void	assert(IOperand*);
    void	load(IOperand*);
    void	store(IOperand*);
    void	pop(void);
    void	dup(void);
    void	clear(void);
    void	swap(void);
    void	print(void);
    void	dump(void);
    void	add(void);
    void	sub(void);
    void	mul(void);
    void	div(void);
    void	mod(void);
    void	exit(void);

    ~CPUComponent();
  };
};

#endif /* !__CPU_COMPONENT_HPP__ */
