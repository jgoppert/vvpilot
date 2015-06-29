all: test-all

build:
	mkdir -p build && cd build && cmake .. && make

build-mc:
	mkdir -p build-mc && cd build-mc && cmake -DCMAKE_TOOLCHAIN_FILE=cmake/goto-toolchain.cmake .. && make

test: build
	cd build && ctest -V

test-mc: build-mc
	cd build-mc && ctest -V

clean:
	rm -rf build build-mc

format: build
	cd build && make format

test-all: test test-mc

cbmc-ubuntu-install:
	./scripts/ubuntu-install.sh

.PHONY: build build-mc clean test-all test test-mc cbmc-ubuntu-install
