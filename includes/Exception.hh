//
// Exception.hh for Exception in /home/jean.walrave/projects/epitech/abstractVM_2016
// 
// Made by Jean Walrave
// Login   <jean.walrave@epitech.net>
// 
// Started on  Fri Jul 21 09:57:52 2017 Jean Walrave
// Last update Sun Jul 23 15:33:35 2017 Jean Walrave
//

#ifndef __EXCEPTION_HH__
# define __EXCEPTION_HH__

# include <iostream>
# include <exception>

namespace Exception
{
  class AVMException : public std::exception
  {
  protected:
    std::string	*_message;
  public:
    AVMException(const std::string&);
    virtual const char	*what() const throw();
    ~AVMException();
  };

  class IOException : public AVMException
  {
  public:
    IOException(const std::string&);
  };

  class OORException : public AVMException
  {
  public:
    OORException(const std::string&);
  };

  class MemoryException : public AVMException
  {
  public:
    MemoryException(const std::string&);
  };

  class CPUException : public AVMException
  {
  public:
    CPUException(const std::string&);
  };
};

#endif /* !__EXCEPTION_HH__ */
