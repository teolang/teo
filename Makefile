all: main

main: main.cpp parse_file.cpp interpret.cpp goto.cpp end.cpp let.cpp print.cpp
	clang++ main.cpp parse_file.cpp interpret.cpp -o main


run: main test/test.teo
	./main --file test/test.teo

clean:
	rm -f main
