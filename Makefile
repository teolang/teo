GIT_VERSION := "$(shell git describe --abbrev=7 --dirty --always --tags)"
TARGET := main.cpp interpret.cpp parse_file.cpp
all: run

cparse/%.o:
	make release -C cparse

main: $(TARGET) cparse/core-shunting-yard.o cparse/builtin-features.o
	clang++ -I cparse $(TARGET) cparse/builtin-features.o cparse/core-shunting-yard.o -o main -DVERSION=\"$(GIT_VERSION)\"

run: main test/test.teo test/loop.teo 
	./main --file test/test.teo --debug
	./main --file test/loop.teo --debug

clean:
	rm -f main cparse/*.o cparse/test-shunting-yard
