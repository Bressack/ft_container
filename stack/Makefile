NAME = stack_tester_bin
NAMESTD = $(NAME)_std

MAIN = stack_main.cpp

all: $(NAME)

$(NAME):
	@ clang++ -O3 -std=c++98 -I . $(MAIN) -o $(NAME)
	@ clang++ -O3 -std=c++98 -I . $(MAIN) -o $(NAMESTD) -D TSTD

clean:
	@ rm -f outft outstd

fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf $(NAMESTD)

re: fclean all

test: fclean all
	@ valgrind ./$(NAME)
	@ time ./$(NAME)
	@ time ./$(NAMESTD)

teststd: fclean all
	@ ./$(NAMESTD)

testft: fclean all
	@ ./$(NAME)