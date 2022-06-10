all:
	@ rm -f tree.dot
	@ clang++ -Wall -Wextra -Werror -O0 -I . main.cpp
	@ # dot -Tpng tree.dot -o tree.png
	@ ./a.out

debug:
	@ rm -f tree.dot
	@ clang++ -Wall -Wextra -Werror -O0 -g3 -fsanitize=address -I . main.cpp
	@ # dot -Tpng tree.dot -o tree.png
	@ lldb ./a.out

init:
	@ (/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)" \
	&& printf "\033[34;01mbrew\033[37;01m correctly installed :)\033[0m\n") \
	|| printf "\033[34;01mbrew\033[31;01m installation error :(\033[0m\n"
	@ brew install graphviz ; brew upgrade graphviz
	@ printf "\033[34;01mgraphviz\033[37;01m correctly installed :)\033[0m\n"
