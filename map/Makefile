NAME = map_tester_bin
NAMESTD = $(NAME)_std

MAIN = map_main.cpp

all: $(NAME)

$(NAME):
	@ clang++ -Wall -Wextra -Werror -O3 -std=c++98 -I . $(MAIN) -o $(NAME)
	@ clang++ -Wall -Wextra -Werror -O3 -std=c++98 -I . $(MAIN) -o $(NAMESTD) -D TSTD

clean:
	@ rm -f outft outstd

fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf $(NAMESTD)

re: fclean all

test: fclean all
	# @ valgrind ./$(NAME)
	time ./$(NAME)
	time ./$(NAMESTD)

teststd: fclean all
	@ ./$(NAMESTD)

testft: fclean all
	@ ./$(NAME)