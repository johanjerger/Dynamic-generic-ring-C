#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring generic functions.
 */

// The size function return the number of ring structs linked.
int dgr_size(ring_t * act_ring)
{
        if (act_ring->elem == NULL) {
                return 0;
        }

        int size = 1;
        ring_t * head = act_ring;

        // while you don't walk in circles...
        while(head->next != act_ring) {
                size++;
                head = head->next;
        }

        return size;
}

// Checks if an elem exist in the ring
bool dgr_exist(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(act_ring->exist_callback(head->elem, elem)) {
                        return true;
                }
                head = head->next;
        }

        return false;
}

// Free all the allocated memory
void dgr_destruct(ring_t * act_ring)
{
}
