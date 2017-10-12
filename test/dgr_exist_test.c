#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "includes/test.h"
#include "../src/includes/dynamic_generic_ring.h"

struct aux_test_str
{
        int aux_int;
        char aux_char;
};

bool exist_callback_test(void * str1, void * str2)
{
        return (((((struct aux_test_str *)str1)->aux_char) == (((struct aux_test_str *)str2)->aux_char))
                && ((((struct aux_test_str *)str1)->aux_int) == (((struct aux_test_str *)str2)->aux_int)));
}

void dgr_exist_test()
{
        struct aux_test_str * aux_str1 = (struct aux_test_str *) malloc(sizeof(struct aux_test_str));
        aux_str1->aux_int = 4;
        aux_str1->aux_char = 'd';
        struct aux_test_str * aux_str2 = (struct aux_test_str *) malloc(sizeof(struct aux_test_str));
        aux_str2->aux_int = 2;
        aux_str2->aux_char = 'c';
        struct aux_test_str * aux_str3 = (struct aux_test_str *) malloc(sizeof(struct aux_test_str));
        aux_str3->aux_int = 7;
        aux_str3->aux_char = 'Z';

        ring_t * ring = new_ring();
        ring->add(ring, aux_str1);
        ring->add(ring, aux_str2);

        ring->set_equals_callback(ring, &exist_callback_test);

        assert(ring->exist(ring, aux_str1) &&
               ring->exist(ring, aux_str2) &&
               (!ring->exist(ring, aux_str3))
               ,"exist");

        free(aux_str1);
        free(aux_str2);
        free(aux_str3);
        ring->destruct(ring);
}
