all: main

main: main.cpp
	clang++ main.cpp parse_file.cpp listelement.cpp -o main

run: main
	./main --file test/test.teo

clean:
	rm -f main
