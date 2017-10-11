#ifndef DGR_OPR_H
#define DGR_OPR_H

/*
 *  Here I define all the ring functions headers.
 */

    int dgr_size(ring_t *);
    ring_t * dgr_add(ring_t *, void *);
    bool dgr_exist(ring_t *, void *);
    void dgr_destruct(ring_t *);

#endif
