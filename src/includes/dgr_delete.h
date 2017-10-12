#ifndef DGR_DEL_H
#define DGR_DEL_H

/*
 *  Here I define all the ring add functions headers.
 */

    ring_t * dgr_delete(ring_t *);
    ring_t * dgr_delete_before(ring_t *);
    ring_t * dgr_delete_next(ring_t *);
    ring_t * dgr_delete_elem(ring_t *, void *);

#endif
