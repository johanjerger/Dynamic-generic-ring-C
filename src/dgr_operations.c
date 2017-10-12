#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring generic functions.
 */

// Checks if an elem exist in the ring
bool dgr_exist(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        return true;
                }
                head = head->next;
        }

        return head->equals_callback(head->elem, elem);
}

// Free all the allocated memory
void dgr_destruct(ring_t * act_ring)
{
        while(act_ring->size > 0) {
                act_ring->delete(act_ring);
        }

        free(act_ring);
}
