all: main

main: main.cpp parse_file.cpp interpret.cpp
	clang++ main.cpp parse_file.cpp interpret.cpp -o main


run: main
	./main --file test/test.teo

clean:
	rm -f main
