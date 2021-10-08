NAME			:= a.out
CC				:= gpp
SRCS			:= test.cpp
RM				:= rm -f

all:
	$(CC) -o $(NAME) $(SRCS)
	./$(NAME)

clean:
	$(RM) -r $(NAME)

re: clean all

tpl:
	cp -n tpl.cpp test.cpp

tplf:
	cp -f tpl.cpp test.cpp


.PHONY: all clean re tpl