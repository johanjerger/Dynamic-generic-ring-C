#include <stdio.h>
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

// Return the count of elements of the ring
int dgr_size(ring_t * act_ring)
{
        ring_t * head = act_ring;
        int size = 0;

        if (head->elem == NULL) return size;

        while(head->next != act_ring) {
                size++;
                head = head->next;
        }

        return ++size;
}

// Print each elem calling the print_callback
void dgr_print(ring_t * act_ring)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                head->print_callback(head->elem);
                head = head->next;
        }

        head->print_callback(head->elem);
}

// Free all the allocated memory
void dgr_destruct(ring_t * act_ring)
{
        while(act_ring->size(act_ring) > 0) {
                act_ring->delete(act_ring);
        }

        free(act_ring);
}
