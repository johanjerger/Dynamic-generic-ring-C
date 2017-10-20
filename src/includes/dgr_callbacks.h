#ifndef DGR_CB_H
#define DGR_CB_H

/*
 *  Here I define all the ring generic functions headers.
 */

    void dgr_set_equals_callback(ring_t *, bool (*)(void *, void *));
    void dgr_set_print_callback(ring_t *, void (*)(void *));

#endif
