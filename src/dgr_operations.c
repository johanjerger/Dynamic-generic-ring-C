#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring functions.
 */

int dgr_size(ring_t * act_ring)
{
        int size = 1;
        ring_t * head = act_ring;

        // while you don't walk in circles...
        while(head->next != act_ring) {
                size++;
                head = head->next;
        }

        return size;
}
