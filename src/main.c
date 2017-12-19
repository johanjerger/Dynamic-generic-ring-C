#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "include/dynamic_generic_ring.h"

/*
 * Later I will define a interface to interact in
 * real time with the ring structure.
 */

bool eq(void * elem1, void * elem2)
{
        return (strcmp((char *) elem1, (char *) elem2) == 0);
}

void prnt(void * elem)
{
        printf(" %s", (char *) elem);
}

int main()
{
        ring_t * ring = new_ring();
        ring->set_print_callback(ring, &prnt);
        printf("opt:\n1 ... add\n2 ... del\n3 ... print\nx ... exit\n\n");

        printf("ring : [");
        ring->print(ring);
        printf(" ]\n");

        int input;
        char elem[1024];

        while(scanf("%d", &input) && input != 7) {
                switch (input) {
                case 1:
                        printf("elem to add: ");
                        scanf("%s\n", elem);
                        (ring->size(ring) == 0) ? ring->add_elem(ring, elem) : ring->add(ring, elem);
                        ring->set_print_callback(ring, &prnt);
                        break;

                case 3:
                        printf("ring : [");
                        ring->print(ring);
                        printf(" ]\n");
                        break;

                case 'x':
                        return 0;
                        break;
                }
        }

        printf("%s\n", (char *) ring->elem);
        printf("%s\n", (char *) ring->next->elem);
        printf("%s\n", (char *) ring->next->next->elem);

        return 0;
}
