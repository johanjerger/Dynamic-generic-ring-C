#include <stdlib.h>
#include "includes/dynamic_generic_ring.h"
#include "includes/dgr_operations.h"

ring_t * new_ring()
{
        ring_t * new_ring;

        new_ring = malloc(sizeof(ring_t));
        new_ring->next = new_ring;
        new_ring->previous = new_ring;
        new_ring->size = &dgr_size;

        return new_ring;
}
