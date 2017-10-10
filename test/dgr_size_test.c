#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "includes/test.h"
#include "../src/includes/dynamic_generic_ring.h"

void dgr_size_test()
{
        ring_t * ring = new_ring();



        free(ring);
}
