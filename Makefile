CTEST_FLAGS ?= ""

all: build-all

build-all: build build-mc

build:
	mkdir -p build && cd build && cmake .. && make

build-mc:
	mkdir -p build-mc && cd build-mc && cmake -DCMAKE_TOOLCHAIN_FILE=cmake/goto-cc-toolchain.cmake .. && make

test: build
	cd build && ctest $(CTEST_FLAGS)

test-mc: build-mc
	cd build-mc && ctest $(CTEST_FLAGS)

clean:
	rm -rf build build-mc

format: build
	cd build && make format

test-all: test test-mc

cbmc-ubuntu-install:
	./scripts/ubuntu-install.sh

graph: build-mc
	cd build-mc && goto-instrument src/vvp/commander/test_commander --dot > graph.dot && sed -i '1d' graph.dot && dot -Tsvg -q graph.dot > graph.svg && eog graph.svg

.PHONY: build build-mc build-all
.PHONY: test test-mc test-all
.PHONY: clean cbmc-ubuntu-install graph
