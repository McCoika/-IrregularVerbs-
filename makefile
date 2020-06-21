run: ./build/src/irregularverbs.o ./build/src/test.o
	g++ -std=c++17 -Wall -Werror -o ./bin/irregularverbs ./build/src/irregularverbs.o ./build/src/test.o -lm

./build/src/irregularverbs.o: ./src/irregularverbs.cpp
	g++ -std=c++17 -c -o ./build/src/irregularverbs.o ./src/irregularverbs.cpp -lm
./build/src/test.o: ./src/test.cpp
	g++ -std=c++17 -c -o ./build/src/test.o ./src/test.cpp -lm
	

clean:
	rm -rf ./build/src/.o ./build/test/.o