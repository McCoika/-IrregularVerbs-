.PHONY: clean
all: run test

run: ./build/src/irregularverbs.o ./build/src/test.o ./build/src/startmenu.o ./build/src/teor.o
	g++ -std=c++17 -Wall -Werror -o ./bin/irregularverbs ./build/src/teor.o ./build/src/startmenu.o ./build/src/test.o ./build/src/irregularverbs.o -lm

./build/src/irregularverbs.o: ./src/irregularverbs.cpp
	g++ -std=c++17 -c -o ./build/src/irregularverbs.o ./src/irregularverbs.cpp -lm
./build/src/test.o: ./src/test.cpp
	g++ -std=c++17 -c -o ./build/src/test.o ./src/test.cpp -lm
./build/src/teor.o: ./src/teor.cpp
	g++ -std=c++17 -c -o ./build/src/teor.o ./src/teor.cpp -lm
./build/src/startmenu.o: ./src/startmenu.cpp
	g++ -std=c++17 -c -o ./build/src/startmenu.o ./src/startmenu.cpp -lm
test: ./build/src/test.o ./build/src/startmenu.o ./build/src/teor.o ./build/test/utest.o
	g++ -Wall -I src -Werror -o ./bin/test ./build/src/test.o ./build/src/startmenu.o ./build/src/teor.o ./build/test/utest.o -lm
	./bin/test
./build/test/utest.o: ./test/utest.cpp
	g++ -std=c++17 -c -o ./build/test/utest.o ./test/utest.cpp -lm
	

clean:
	rm -rf ./build/src/*.o ./build/test/*.o