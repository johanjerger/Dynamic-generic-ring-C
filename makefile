SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

CFLAG=-Ofast -Wall -std=gnu11 -Wpedantic -Werror -fpic
#DEBUG=-g

dgr_c_files = dynamic_generic_ring dgr_operations dgr_add dgr_callbacks
dgr_test_c_files = main_test test dgr_new_test dgr_add_test dgr_size_test \
									 dgr_exist_test

.PHONY: all test clean install uninstall reinstall compile_install test-run lines
.IGNORE: clean

all: clean folders main.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/dgr $(CFLAG) $(DEBUG)

test: clean folders test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/dgr_test $(CFLAG) $(DEBUG)

main.o: dgr.o
		#MAIN
		gcc -c $(SOURCE_FOLDER)/main.c -o $(TEMPORAL_FOLDER)/main.o $(CFLAG) $(DEBUG)

test.o: dgr.o
		#TEST CLASES
		for file in $(dgr_test_c_files); do \
		gcc -c $(TEST_FOLDER)/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
done

		#UTILITIES
		gcc -c $(TEST_FOLDER)/utilities/utilities.c -o $(TEMPORAL_FOLDER)/utilities.o $(CFLAG) $(DEBUG); \

dgr.o:
		# DGR STRUCTURE
		for file in $(dgr_c_files); do \
		gcc -c $(SOURCE_FOLDER)/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
done

install: $(BUILD_FOLDER)/dgr; cp -p $(BUILD_FOLDER)/dgr $(INSTALL_FOLDER)

uninstall: $(INSTALL_FOLDER)/dgr; rm $(INSTALL_FOLDER)/dgr

reinstall: uninstall install

clean: ; -rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders: ; -mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

lines:
		@ printf "	.c files              "
		@ find $(SOURCE_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h files      	       "
		@ find $(SOURCE_FOLDER)/ -name '*.h' | xargs wc -l | grep total
		@ printf "	.c test files          "
		@ find $(TEST_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h test files 	        "
		@ find $(TEST_FOLDER)/ -name '*.h' | xargs wc -l | grep total

compile_install: all install

test-run: test ; @ ./$(BUILD_FOLDER)/dgr_test
