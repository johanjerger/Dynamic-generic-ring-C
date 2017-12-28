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

        for (int i = 0; i < act_ring->size; i++) {
                if(head->equals_callback(head->elem, elem)) {
                        return true;
                }
                head = head->next;
        }

        return false;
}

bool dgr_count(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;
        int result = 0;

        for (int i = 0; i < act_ring->size; i++) {
                if(head->equals_callback(head->elem, elem)) {
                        result++;
                }
                head = head->next;
        }

        return result;
}

// Print each elem calling the print_callback
void dgr_print(ring_t * act_ring)
{
        ring_t * head = act_ring;

        printf("[");
        for (int i = 0; i < act_ring->size - 1; i++) {
                head->print_callback(head->elem);
                printf(" ,");
                head = head->next;
        }
        head->print_callback(head->elem);
        printf("]\n");
}

// Free all the allocated memory
void dgr_destruct(ring_t * act_ring)
{
        while(act_ring->size > 0) {
                act_ring->delete(act_ring);
        }
        free(act_ring);
}
