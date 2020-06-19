run: ./build/src/irregularverbs.o
	g++ -std=c++17 -Wall -Werror -o ./bin/irregularverbs ./build/src/irregularverbs.o -lm

./build/src/irregularverbs.o: ./src/irregularverbs.cpp
	g++ -std=c++17 -c -o ./build/src/irregularverbs.o ./src/irregularverbs.cpp -lm
clean:
	rm -rf ./build/src/.o ./build/test/.o