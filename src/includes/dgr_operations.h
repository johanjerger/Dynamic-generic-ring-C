#ifndef DGR_OPR_H
#define DGR_OPR_H

/*
 *  Here I define all the ring generic functions headers.
 */

    int dgr_size(ring_t *);
    bool dgr_exist(ring_t *, void *);
    void dgr_destruct(ring_t *);

#endif
