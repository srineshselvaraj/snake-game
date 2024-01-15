all:
	g++ -I src/Include -L src/lib -o main main.cpp snake.cpp segment.cpp food.cpp menu.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf