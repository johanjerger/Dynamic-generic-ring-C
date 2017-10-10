#include "includes/dynamic_generic_ring.h"


int dgr_size(ring_t * act_ring)
{
        int size = 1;
        ring_t * head = act_ring;

        while(head->next != act_ring) {
                size++;
                head = head->next;
        }

        return size;
}
