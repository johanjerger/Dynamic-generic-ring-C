#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

// The delete function delete an element on before the actual ring position.
void * dgr_pop_back(ring_t * ring)
{
        ring_t * new_previous = ring->last()->previous;
        new_previous->next = ring;
        free(ring->previous);
        ring->previous = new_previous;
}

// The delete function delete an element on after the actual ring position.
void * dgr_pop_at(ring_t * ring, int pos)
{
        ring_t * new_previous = ring->at(pos)->previous;
        new_previous->next = ring;
        free(ring->previous);
        ring->previous = new_previous;
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
