#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includes/dynamic_generic_ring.h"

/*
 *      Definition of insert functions
 *     ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 *
 *    The definition of the insert functions is a 'fragil' issue,
 *    because the ring_t don't have a really semantic begin or
 *    end, I use the position policy (insert after the last
 *    item inserted).
 *
 *    Is needed to mention, that the ring_t is a zero-indexed
 *    data structure.
 *
 */

/*
 *    'dgr_push' defines the insert to the end function,
 *    basicly, if the last position set is five, your pushed
 *    item will be in the position six.
 *
 */

void dgr_push(ring_t * ring, void * elem)
{
        printf("push!\n");
        ring_node_t * node = new_node(elem);
        new_node->next = ring->begin();
        new_node->previous = ring->last();
        ring->last()->next = new_node;
        ring->begin()->previous = new_node;
        ring->size++;
}

/*
 *    'dgr_put_in' defines the insert to an specific position
 *    in the ring_t structure, this is intended to be a facility
 *    to modify a ring in a more dinamic way.
 *
 *    Note: This function delete the previous value in the
 *    ring position!
 *
 */

void dgr_put_in(ring_t * ring, void * elem, int pos)
{
        printf("put_in!\n");
        ring_node_t * node = new_node(elem);
        new_node->next = ring->at(pos + 1);
        new_node->previous = ring->at(pos - 1);
        ring->at(pos + 1)->previous = new_node;
        ring->at(pos - 1)->next = new_node;
        ring->size++;
}

/*
 *    'dgr_fill_in' defines the insert to an specific position
 *    in the ring_t structure, this is intended to be a facility
 *    to modify a ring in a more dinamic way.
 *
 *    Note: This function is an alternative to the dgr_put_in
 *    function, this don't delete the previous value in The
 *    ring position, this function put forward the element in
 *    the position passed an fills the empty slot with the new
 *    element.
 *
 */

void dgr_fill_in(ring_t * ring, void * elem, int pos)
{
        printf("fill_in!\n");
        ring_node_t * node = new_node(elem);
        node->next = ring->at(pos);
        node->previous = ring->at(pos - 1);
        ring->at(pos)->previous = node;
        ring->at(pos - 1)->next = node;
        ring->size++;
}
