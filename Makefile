.POSIX:
.SUFFIXES:

all: build

build: test
	@echo "done"

test: compile
	@echo "testing ..."

compile:
	# checkout build in inference rules for C

clean: clean_object_files clean_executable
	@echo "done"
clean_object_files:
	@echo "cleaning object files ..."
	rm -f "$$(find "./" -type f -name "*.o")"
clean_executable:
	
