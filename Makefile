all:
# mkdir build
	g++ -o build/main -ggdb ./src/*.cpp -O3 -ggdb -lm -lGL -lSDL2 -Isrc/include -fsanitize=address