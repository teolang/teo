GIT_VERSION := "$(shell git describe --abbrev=4 --dirty --always --tags)"
all: clean main run

main: $(wildcard $(SRC_DIR)/*.cpp,h)
	clang++ main.cpp parse_file.cpp interpret.cpp -o main -DVERSION=\"$(GIT_VERSION)\"


run: main test/test.teo
	./main --file test/test.teo --debug

clean:
	rm -f main
