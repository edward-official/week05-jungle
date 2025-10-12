########## Project settings
CC      := gcc
CFLAGS  := -Wall -Wextra -g -Iunity -Itasks/phase1
########## Only implementation sources required by tests (no files with main())
SRC     := unity/unity.c tasks/phase1/HeaderLinkedList.c

########## Tests discovery
########## Automatically find tests/LinkedListTest*.c and build executables in the build/ directory with matching names.
TEST_CS   := $(wildcard tests/LinkedListTest*.c)
TEST_BINS := $(patsubst tests/%.c,build/%,$(TEST_CS))

########## Default target
.PHONY: all
all: $(TEST_BINS)

########## Individual test binary build rule
########## Example: build/LinkedListTest7 is built from tests/LinkedListTest7.c + $(SRC)
build/%: tests/%.c $(SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) $< $(SRC) -o $@

########## Run all tests
.PHONY: test
test: $(TEST_BINS)
	@set -e; \
	for t in $^ ; do \
	  echo "===== Running $$t ====="; \
	  ./$$t; \
	  echo; \
	done

########## Run a specific test
########## Usage: make run TEST=LinkedListTest7
.PHONY: run
run:
	@if [ -z "$(TEST)" ]; then \
	  echo "Usage: make run TEST=LinkedListTest7"; exit 1; \
	fi
	@$(MAKE) build/$(TEST)
	@echo "===== Running build/$(TEST) ====="
	@./build/$(TEST)

########## Clean build artifacts
.PHONY: clean
clean:
	rm -rf build
