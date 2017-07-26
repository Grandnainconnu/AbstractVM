##
## Makefile for Makefile in /home/jean.walrave/projects/epitech/abstractVM_2016
## 
## Made by Jean Walrave
## Login   <jean.walrave@epitech.net>
## 
## Started on  Thu Jul 20 10:46:23 2017 Jean Walrave
## Last update Wed Jul 26 09:05:02 2017 Jean Walrave
##

PROJECT		= abstractVM

SRCS		= sources/AbstractVM.cpp \
		  sources/Exception.cpp \
		  sources/Factory.cpp \
		  sources/component/CPUComponent.cpp \
		  sources/component/MemoryComponent.cpp \
		  sources/component/ChipsetComponent.cpp \
		  sources/component/IOComponent.cpp \
		  sources/operand/Int8.cpp \
		  sources/operand/Int16.cpp \
		  sources/operand/Int32.cpp \
		  sources/operand/Float.cpp \
		  sources/operand/Double.cpp \
		  sources/operand/BigDecimal.cpp \
		  sources/operand/AbstractOperand.cpp \

OBJS		= $(SRCS:.cpp=.o)

CXX		= g++

RM		= rm -rf

CFLAGS		+= -std=c++14 -W -Wall -Werror

CPPFLAGS	+= -Iincludes/

all: $(PROJECT)

$(PROJECT): $(OBJS)
	    $(CXX) -o $(PROJECT) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PROJECT)

re: fclean all

.PHONY: all clean fclean re
