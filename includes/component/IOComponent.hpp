//
// IOComponent.hh for IO component in /home/jean.walrave/projects/epitech/abstractVM_2016/includes
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Thu Jul 20 21:27:51 2017 Jean Walrave
// Last update Tue Jul 25 20:42:29 2017 Jean Walrave
//

#ifndef __IO_COMPONENT_HPP__
# define __IO_COMPONENT_HPP__

# include <regex>
# include <fstream>
# include <list>
# include "operand/IOperand.hpp"

namespace AVMComponent
{
  class IOComponent
  {
  private:
    std::list<std::pair<std::string, std::list<std::string>>>	_instructions;
  public:
    IOComponent() = default;
    IOComponent(const IOComponent&);

    bool	parseInstruction(std::string&, std::pair<std::string, std::list<std::string>>&);
    void	readInstructions(std::istream&, bool = false);
    void	dump(const std::vector<IOperand*>&);
    void	print(const IOperand*) const;

    const std::list<std::pair<std::string, std::list<std::string>>>&	getInstructions(void) const;

    ~IOComponent() = default;
  };
};

#endif /* !__IO_COMPONENT_HPP__ */
