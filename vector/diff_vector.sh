clang++ -std=c++98 main.cpp -D NS=ft && ./a.out > diff_me
clang++ -std=c++98 main.cpp -D NS=std && ./a.out > diff_std
diff -ar diff_me diff_std
rm -f diff_me diff_std
