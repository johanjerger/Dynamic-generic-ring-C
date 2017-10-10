#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "includes/test.h"
#include "../src/includes/dynamic_generic_ring.h"

void dgr_new_test()
{
        ring_t * ring = new_ring();

        assert(malloc_usable_size(ring) > 0,
               "new");

        printf("%d\n", ring->size(ring));

        free(ring);
}
