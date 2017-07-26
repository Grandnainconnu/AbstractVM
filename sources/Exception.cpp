//
// Exception.cpp for Exception in /home/jean.walrave/projects/epitech/abstractVM_2016/sources
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 09:52:13 2017 Jean Walrave
// Last update Sun Jul 23 15:33:54 2017 Jean Walrave
//

#include "Exception.hh"

Exception::AVMException::AVMException(const std::string& message) : _message(new std::string(message))
{
  ;
}

const char	*Exception::AVMException::what() const throw()
{
  return (this->_message->c_str());
}

Exception::AVMException::~AVMException()
{
  if (this->_message)
    delete (this->_message);
}

Exception::IOException::IOException(const std::string& message)
  : Exception::AVMException(message)
{
  ;
}

Exception::OORException::OORException(const std::string& message)
  : Exception::AVMException(message)
{
  ;
}

Exception::MemoryException::MemoryException(const std::string& message)
  : Exception::AVMException(message)
{
  ;
}

Exception::CPUException::CPUException(const std::string& message)
  : Exception::AVMException(message)
{
  ;
}
