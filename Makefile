GIT_VERSION := "$(shell git describe --abbrev=7 --dirty --always --tags)"
all: clean prepare main run

prepare:
	make release -C cparse

main: $(wildcard $(SRC_DIR)/*.cpp,h)
	clang++ -I cparse main.cpp parse_file.cpp interpret.cpp cparse/builtin-features.o cparse/core-shunting-yard.o -o main -DVERSION=\"$(GIT_VERSION)\"

run: main test/test.teo test/loop.teo
	./main --file test/test.teo --debug
	./main --file test/loop.teo --debug

clean:
	rm -f main
