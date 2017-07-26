//
// IOComponent.cpp for IOComponent in /home/jean.walrave/projects/epitech/abstractVM_2016/sources
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Thu Jul 20 12:40:24 2017 Jean Walrave
// Last update Tue Jul 25 20:47:28 2017 Jean Walrave
//

#include <regex>
#include "Exception.hh"
#include "component/IOComponent.hpp"

AVMComponent::IOComponent::IOComponent(const IOComponent& component)
{
  this->_instructions = component.getInstructions();
}

const std::list<std::pair<std::string, std::list<std::string>>>&
AVMComponent::IOComponent::getInstructions(void) const
{
  return (this->_instructions);
}

void
AVMComponent::IOComponent::dump(const std::vector<IOperand*>& operands)
{
  for (const auto& operand : operands)
    {
      std::size_t	position;

      if ((position = operand->toString().find(".")) != std::string::npos)
	{
	  std::string	cOperand = operand->toString();

	  cOperand.erase(cOperand.find_last_not_of('0') + 1, std::string::npos);

	  if (position + 1 == cOperand.size())
	    cOperand.erase(position);
	  else if (cOperand.size() - (position + 1) > operand->getPrecision())
	    cOperand.erase(position + operand->getPrecision() + 1 , std::string::npos);

	  std::cout << cOperand << std::endl;
	}
      else
	std::cout << operand->toString() << std::endl;
    }
}

void
AVMComponent::IOComponent::print(const IOperand* operand) const
{
  short	cValue;

  std::istringstream(operand->toString()) >> cValue;

  std::cout << static_cast<char>(cValue) << std::endl;
}

const std::string
epurString(std::string& str)
{
  std::string		w, value;
  std::istringstream	iss(str);

  if (iss >> w)
    value += w;

  for (int i = 0; iss >> w; i++)
    {
      if (!i)
	value += ' ';
      value += w;
    }

  return (value);
}

bool
AVMComponent::IOComponent::parseInstruction(std::string& l, std::pair<std::string, std::list<std::string>>& instruction)
{
  std::regex	simpleInstructionPattern("^(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit)");
  std::regex	withValueInstructionPatternWF("^(push|assert|load|store) (int8|int16|int32|bigdecimal)\\((-?[[:d:]]+)\\)");
  std::regex	withValueInstructionPatternF("^(push|assert|load|store) (float|double|bigdecimal)\\((-?[[:d:]]+\\.?[[:d:]]+?)\\)");
  std::smatch	matches;

  if (l.empty() or l.at(0) == ';')
    return (false);

  if (regex_search(l, matches, withValueInstructionPatternWF) or regex_search(l, matches, withValueInstructionPatternF))
    instruction = std::make_pair(matches[1], std::list<std::string>{matches[2], matches[3]});
  else if (regex_search(l, matches, simpleInstructionPattern))
    instruction = std::make_pair(matches[0], std::list<std::string>{});
  else
    throw Exception::IOException("Unknown or invalid instruction '" + l  + "'.");
  return (true);
}

void
AVMComponent::IOComponent::readInstructions(std::istream& input, bool isFile)
{
  std::pair<std::string, std::list<std::string>>	instruction;
  std::list<std::string>				instructions;

  if (false == input.good())
    throw Exception::IOException("Unable to read instructions.");

  for (std::string l; input.good() and getline(input, l); )
    {
      l = epurString(l);

      instructions.push_back(l);

      if (false == isFile and ";;" == l)
	break;
    }

  for (auto& l : instructions)
    if (this->parseInstruction(l, instruction) == true)
      this->_instructions.push_back(instruction);

  if (this->_instructions.empty())
    throw Exception::IOException("No instructions.");

  if (false == isFile and ";;" != instructions.back())
    throw Exception::IOException("Standard input stopped without ';;' instruction.");
  else if ("exit" != this->_instructions.back().first)
    throw Exception::IOException("Instructions unterminated by 'exit'.");
}
