GCOVR ?= OFF

CMAKE_ARGS ?= \
	-DGCOVR=$(GCOVR)

.PHONY: all clean test build

all: build test

build:
	cmake -B build $(CMAKE_ARGS)
	cmake --build build -j

test: build
	@./build/test/all_tests

clean:
	rm -rf build