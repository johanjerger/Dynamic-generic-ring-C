#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include "includes/dgr_new_test.h"
#include "includes/dgr_add_test.h"
#include "includes/dgr_size_test.h"

/*
 * This is the test main function,
 * here I manage the order of the
 * test functions.
 */

int main()
{
        make_header();

        make_test_title("dgr");

        dgr_new_test();

        dgr_add_test();

        dgr_size_test();

        end_test_title("dgr");

        make_footer();

        return 0;
}
