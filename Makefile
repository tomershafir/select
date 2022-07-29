.POSIX:
.SUFFIXES:

all: build

build: test
	@echo "done"

test: compile
	@echo "testing ..."

compile:


clean: clean_object_files
	@echo "done"
clean_object_files:
	@echo "cleaning object files ..."
	rm -f "$$(find "./" -type f -name "*.o")"
