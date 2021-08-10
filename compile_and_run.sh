clang++ -c *.cpp -I ../../../Downloads/SFML-2.5.1/include/ -std=c++2a
clang++ *.o -L ../../../Downloads/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -o pacman

./pacman
