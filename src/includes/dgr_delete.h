#ifndef DGR_DEL_H
#define DGR_DEL_H

/*
 *  Here I define all the ring add functions headers.
 */

    void dgr_delete(ring_t *);
    void dgr_delete_before(ring_t *);
    void dgr_delete_next(ring_t *);
    void dgr_delete_elem(ring_t *, void *);
    void dgr_delete_all_elem(ring_t *, void *);
    void dgr_delete_next_elem_to(ring_t *, void *);
    void dgr_delete_before_elem_to(ring_t *, void *);

#endif
