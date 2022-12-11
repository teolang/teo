all: clean main run

main: $(wildcard $(SRC_DIR)/*.cpp,h)
	clang++ main.cpp parse_file.cpp interpret.cpp -o main


run: main test/test.teo
	./main --file test/test.teo --debug

clean:
	rm -f main
