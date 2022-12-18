GIT_VERSION := "$(shell git describe --abbrev=7 --dirty --always --tags)"
all: clean main run

main: $(wildcard $(SRC_DIR)/*.cpp,h)
	clang++ -I cparse main.cpp parse_file.cpp interpret.cpp cparse/builtin-features.o cparse/core-shunting-yard.o -o main -DVERSION=\"$(GIT_VERSION)\"


run: main test/test.teo
	./main --file test/test.teo --debug

clean:
	rm -f main
