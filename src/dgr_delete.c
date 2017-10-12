#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring add functions.
 */

// The delete function delete an element on before the actual ring position.
ring_t * dgr_delete_before(ring_t * act_ring)
{
        if (act_ring->size == 0) {
                return act_ring;
        }
        if (act_ring->size == 1) {
                act_ring->size--;
                return act_ring->elem = NULL;
        }

        act_ring->size--;

        ring_t * new_previous = act_ring->previous->previous;
        new_previous->next = act_ring;
        free(act_ring->previous);
        act_ring->previous = new_previous;

        return act_ring;
}

// The delete function delete an element on after the actual ring position.
ring_t * dgr_delete_next(ring_t * act_ring)
{
        if (act_ring->size == 0) {
                return act_ring;
        }
        if (act_ring->size == 1) {
                act_ring->size--;
                return act_ring->elem = NULL;
        }

        act_ring->size--;

        ring_t * new_next = act_ring->next->next;
        new_next->previous = act_ring;
        free(act_ring->next);
        act_ring->next = new_next;

        return act_ring;
}

// This function deletes a particular elem in the ring
ring_t * dgr_delete_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete(head->next);
                        return act_ring;
                }
                head = head->next;
        }

        return act_ring;
}


// This function deletes all the elems that are like your elem
ring_t * dgr_delete_all_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete(head->next);
                        return act_ring;
                }
                head = head->next;
        }

        return act_ring;
}

// This function deletes the next elem after the elem like you pass
ring_t * dgr_delete_next_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete_next(head);
                }
                head = head->next;
        }

        return act_ring;
}

// This function deletes the before elem after the elem like you pass
ring_t * dgr_delete_before_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete_before(head);
                }
                head = head->next;
        }

        return act_ring;
}


// This method is a wrapper of dgr_delete_before
ring_t * dgr_delete(ring_t * act_ring)
{
        return act_ring->delete_before(act_ring);
}
