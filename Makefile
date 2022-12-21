GIT_VERSION := "$(shell git describe --abbrev=7 --dirty --always --tags)"
TARGET := main.cpp interpret.cpp parse_file.cpp
COMMAND_LIST := assert.cpp end.cpp goto.cpp let.cpp print.cpp
UTILITIES := codelistHandler.cpp parse_file.cpp parse_file.h interpret.cpp interpret.h 
CPARSE_DEPENDENCIES := cparse/core-shunting-yard.o cparse/builtin-features.o

PLATFORM ?= $(shell uname -s || echo unknown)
ifneq ($(filter unknown Darwin, $(PLATFORM)),)
	override PLATFORM := $(shell $(CXX) -dumpmachine | awk -F"-" '{ print (NF==4) ? $$3 : $$2 }')
	ifeq ($(PLATFORM),apple)
		override PLATFORM := macos
	endif
endif
ifeq ($(shell uname -v | grep ARM64 >/dev/null 2>&1; echo $$?),0)
	ARCH ?= arm64
else
	ARCH ?= $(shell $(CXX) -dumpmachine | cut -d "-" -f 1)
endif

all: verbose run

verbose:
	@printf " $(shell cat banner)\n"
	@printf "\033[1;92mPLATFORM   \033[1;93m?| \033[0m$(PLATFORM)\n"
	@printf "\033[1;96mARCH       \033[1;93m?| \033[0m$(ARCH)\n"
	@printf "\n\n"

cparse/%.o:
	@printf "\033[1;92mMaking   \033[1;93m>> \033[0mCPARSE\n"
	make release -C cparse

main: main.cpp $(COMMAND_LIST) $(UTILITIES) $(CPARSE_DEPENDENCIES)
	@printf "\033[1;92mMaking   \033[1;93m>> \033[0mMain file\n"
	clang++ -I cparse $(TARGET) $(CPARSE_DEPENDENCIES) -o main -DVERSION=\"$(GIT_VERSION)\"

run: main test/test.teo test/loop.teo 
	@printf "\033[1;92mTesting   \033[1;93m \033[0mtest.teo\n"
	./main --file test/test.teo --debug
	@printf "\033[1;92mTesting   \033[1;93m \033[0mloop.teo\n"
	./main --file test/loop.teo --debug
	@printf "\033[1;92mTesting   \033[1;93m \033[0mcircle.teo\n"
	./main --file test/circle.teo --debug

clean:
	rm -f main cparse/*.o cparse/test-shunting-yard

