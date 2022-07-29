.POSIX:
.SUFFIXES:

EXECUTABLE_NAME=a.out
SRC_DIR=src
TARGET_DIR=object

all: build

build: test
	@echo "done"

test: compile
	@echo "test ..."

compile: mktdir report_compile $(TARGET_DIR)/$(EXECUTABLE_NAME)
mktdir:
	@echo "make target directory ..."
	mkdir -p $(TARGET_DIR)
report_compile:
	@echo "compile ..."
$(TARGET_DIR)/$(EXECUTABLE_NAME): $(TARGET_DIR)/main.o $(TARGET_DIR)/select.o
	gcc -Wall -pedantic -g $(TARGET_DIR)/main.o $(TARGET_DIR)/select.o -o $@
$(TARGET_DIR)/main.o: $(SRC_DIR)/select.h $(SRC_DIR)/main.c
	gcc -c -ansi -Wall -pedantic -g $(SRC_DIR)/main.c -o $@
$(TARGET_DIR)/select.o: $(SRC_DIR)/select.c $(SRC_DIR)/select.h
	gcc -c -ansi -Wall -pedantic -g $(SRC_DIR)/select.c -o $@

clean: clean_executable clean_object_files
	@echo "done"
clean_executable:
	@echo "clean executable ..."
	rm -f "$$(find "$(TARGET_DIR)" -type f -name "$(EXECUTABLE_NAME)")"
clean_object_files:
	@echo "clean object files ..."
	rm -f "$$(find "$(TARGET_DIR)" -type f -name "*.o")"
