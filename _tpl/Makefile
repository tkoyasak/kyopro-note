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

abc:
	touch contest/{a..f}.cpp
	fd cpp contest | xargs -n 1 cp tpl.cpp

a:
	$(CC) -o $(NAME) contest/a.cpp
	./$(NAME)

b:
	$(CC) -o $(NAME) contest/b.cpp
	./$(NAME)

c:
	$(CC) -o $(NAME) contest/c.cpp
	./$(NAME)

d:
	$(CC) -o $(NAME) contest/d.cpp
	./$(NAME)

e:
	$(CC) -o $(NAME) contest/e.cpp
	./$(NAME)

f:
	$(CC) -o $(NAME) contest/f.cpp
	./$(NAME)


.PHONY: all clean tpl
