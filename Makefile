CTEST_FLAGS ?= ""

BUILD_DIRS=build build-mc build-arm

all: build-all

build-all: $(BUILD_DIRS)

build:
	mkdir -p build && cd build && cmake .. && make

build-mc:
	mkdir -p build-mc && cd build-mc && cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-goto-cc.cmake .. && make

build-arm:
	mkdir -p build-arm && cd build-arm && cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-arm-none-eabi.cmake .. && make

test: build
	cd build && ctest $(CTEST_FLAGS)

test-mc: build-mc
	cd build-mc && ctest $(CTEST_FLAGS)

clean:
	rm -rf $(BUILD_DIRS)

format: build
	cd build && make format

test-all: test test-mc

cbmc-ubuntu-install:
	./scripts/ubuntu-install.sh

graph: build-mc
	cd build-mc && goto-instrument src/vvp/modules/commander/test_commander --dot > graph.dot && sed -i '1d' graph.dot && dot -Tsvg -q graph.dot > graph.svg && eog graph.svg

.PHONY: build build-mc build-all build-arm
.PHONY: test test-mc test-all
.PHONY: clean cbmc-ubuntu-install graph
