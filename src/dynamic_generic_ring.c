#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"
#include "includes/dgr_operations.h"
#include "includes/dgr_callbacks.h"
#include "includes/dgr_add.h"
#include "includes/dgr_delete.h"

/*
 * Here I define the interface of the ring_t structure.
 */

ring_t * new_ring()
{
        ring_t * new_ring;

        new_ring = (ring_t *) malloc(sizeof(ring_t));
        new_ring->elem = NULL;
        new_ring->next = new_ring;
        new_ring->previous = new_ring;

        // Ring functions assignation

        new_ring->add_elem = &dgr_add_elem;
        new_ring->add = &dgr_add;
        new_ring->add_before = &dgr_add_before;
        new_ring->add_next = &dgr_add_next;
        new_ring->exist = &dgr_exist;
        new_ring->print = &dgr_print;
        new_ring->size = &dgr_size;
        new_ring->delete_before = &dgr_delete_before;
        new_ring->delete = &dgr_delete;
        new_ring->delete_next = &dgr_delete_next;
        new_ring->delete_elem = &dgr_delete_elem;
        new_ring->delete_all_elem = &dgr_delete_all_elem;
        new_ring->delete_next_elem_to = &dgr_delete_next_elem_to;
        new_ring->delete_before_elem_to = &dgr_delete_before_elem_to;

        // Callbacks

        new_ring->set_equals_callback = &dgr_set_equals_callback;
        new_ring->set_print_callback = &dgr_set_print_callback;

        // Destroy functions

        new_ring->destruct = &dgr_destruct;

        return new_ring;
}
