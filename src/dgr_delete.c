#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *  Here I define all the ring add functions.
 */

static bool dgr_empty_delete(ring_t * act_ring)
{
        if (act_ring->size(act_ring) == 0) {
                return true;
        }
        if (act_ring->size(act_ring) == 1) {
                act_ring->elem = NULL;
                return true;
        }
        return false;
}

// The delete function delete an element on before the actual ring position.
void dgr_delete_before(ring_t * act_ring)
{
        if(dgr_empty_delete(act_ring)) return;

        ring_t * new_previous = act_ring->previous->previous;
        new_previous->next = act_ring;
        free(act_ring->previous);
        act_ring->previous = new_previous;
}

// The delete function delete an element on after the actual ring position.
void dgr_delete_next(ring_t * act_ring)
{
        if(dgr_empty_delete(act_ring)) return;

        ring_t * new_next = act_ring->next->next;
        new_next->previous = act_ring;
        free(act_ring->next);
        act_ring->next = new_next;
}

// This function deletes a particular elem in the ring
void dgr_delete_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete(head->next);
                        return;
                }
                head = head->next;
        }
}


// This function deletes all the elems that are like your elem
void dgr_delete_all_elem(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete(head->next);
                }
                head = head->next;
        }
}

// This function deletes the first ocurrensy next elem after the elem
// like you pass
void dgr_delete_next_elem_to(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete_next(head);
                        return;
                }
                head = head->next;
        }
}

// This function deletes the first ocurrensy before elem after the elem
// like you pass
void dgr_delete_before_elem_to(ring_t * act_ring, void * elem)
{
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                if(head->equals_callback(head->elem, elem)) {
                        head->delete_before(head);
                        return;
                }
                head = head->next;
        }
}


// This method is a wrapper of dgr_delete_before
void dgr_delete(ring_t * act_ring)
{
        act_ring->delete_before(act_ring);
}
