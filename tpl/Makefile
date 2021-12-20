NAME    := a.out
CC      := gpp
SRC     := test.cpp
RM      := rm -f

all:
	$(CC) -o $(NAME) $(SRC)	
	./$(NAME)

clean:
	$(RM) -r $(NAME)

tpl:
	cp -f tpl.cpp test.cpp

.PHONY: all clean tpl
