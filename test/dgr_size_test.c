#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "includes/test.h"
#include "../src/includes/dynamic_generic_ring.h"

void dgr_size_test()
{
        ring_t * ring = new_ring();
        ring_t * empty_ring = new_ring();
        char * test_data1 = "test1";
        char * test_data2 = "test2";
        char * test_data3 = "test3";
        char * test_data4 = "test4";
        char * test_data5 = "test5";
        char * test_data6 = "test6";

        ring->add(ring, test_data1);
        ring->add(ring, test_data2);
        ring->add(ring, test_data3);
        ring->add(ring, test_data4);
        ring->add(ring, test_data5);
        ring->add(ring, test_data6);

        assert((ring->size == 6) &&
               (empty_ring->size == 0),
               "size");

        free(ring);
}
