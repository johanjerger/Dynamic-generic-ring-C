#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

void make_header()
{
        printf(GREEN "\n\t  ... STARTING TESTS ...  \t\n" RESET);
}

void make_footer()
{
        printf(GREEN "\n\t  ... TESTS DONE ...  \t\n\n" RESET);
}

void make_test_title(char * test_name)
{
        printf(GREEN "\n BEGINING %s TEST\n\n" RESET, test_name);
        btt_sleep(500);
}

void assert(bool success, char * method)
{
        // assert method to avoid the duplicate code in tests...

        // the spaces variable is only for output purpose
        char spaces[] = "          ";
        int size_of_spaces = strlen(spaces) - strlen(method);
        spaces[size_of_spaces] = '\0';

        // printing the test result.
        (success) ?
        printf(GREEN "\t - %s method %s ..............................     SUCCESS \n" RESET, method, spaces) :
        fprintf(stderr, RED "\t - %s method %s ..............................     FAIL \n" RESET, method, spaces);
        btt_sleep(500);
}

void end_test_title(char * test_name)
{
        printf(GREEN "\n %s TEST FINISH\n\n" RESET, test_name);
}
