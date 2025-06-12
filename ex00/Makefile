NAME = megaphone

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $NAME

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

