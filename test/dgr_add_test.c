#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "includes/test.h"
#include "../src/includes/dynamic_generic_ring.h"

struct aux_test_str
{
        int aux_int;
        char aux_char;
};


void dgr_add_test()
{
        ring_t * ring = new_ring();
        int * int_test = (int *) malloc(sizeof(int));
        char * str_test = "test";
        *int_test = 4;
        struct aux_test_str * aux_str = (struct aux_test_str *) malloc(sizeof(struct aux_test_str));
        aux_str->aux_int = 2;
        aux_str->aux_char = 'c';

        ring->add(ring, int_test);
        ring->add(ring, str_test);
        ring->add(ring, aux_str);

        assert((((int *) ring->elem) == int_test) &&
               (strcmp(((char *) ring->next->elem), str_test) == 0) &&
               ((((struct aux_test_str *) ring->previous->elem)->aux_char) == aux_str->aux_char) &&
               ((((struct aux_test_str *) ring->previous->elem)->aux_int) == aux_str->aux_int),
               "add_before");

        ring->add_next(ring, int_test);
        ring->add_next(ring, int_test);
        ring->add_next(ring, int_test);

        assert((((int *) ring->next->elem) == int_test) &&
               (((int *) ring->next->next->elem) == int_test) &&
               (((int *) ring->next->next->next->elem) == int_test),
               "add_next");

        free(int_test);
        free(aux_str);
        ring->destruct(ring);
}
