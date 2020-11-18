NAME = assignment1

none:
	g++ -o $(NAME) $(wildcard *.cpp)

all: $(NAME).exe

$(NAME).exe: $(subst .cpp,.o,$(wildcard *.cpp))
	g++ -o $(NAME) $^

%.o: %.cpp $(wildcard *.h)
	g++ -c $< -o $@

clean:
	del *.o; del $(NAME).exe

.PHONY: clean none all
