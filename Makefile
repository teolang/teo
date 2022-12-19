GIT_VERSION := "$(shell git describe --abbrev=7 --dirty --always --tags)"
TARGET := main.cpp interpret.cpp parse_file.cpp
all: run

cparse/%.o:
	make release -C cparse

main: assert.cpp codelistHandler.cpp end.cpp goto.cpp interpret.cpp interpret.h let.cpp main.cpp parse_file.cpp parse_file.h print.cpp cparse/core-shunting-yard.o cparse/builtin-features.o
	clang++ -I cparse $(TARGET) cparse/builtin-features.o cparse/core-shunting-yard.o -o main -DVERSION=\"$(GIT_VERSION)\"

run: main test/test.teo test/loop.teo 
	./main --file test/test.teo --debug
	./main --file test/loop.teo --debug
	./main --file test/circle.teo --debug

clean:
	rm -f main cparse/*.o cparse/test-shunting-yard
