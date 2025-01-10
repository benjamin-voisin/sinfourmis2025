#ifndef MEMOIRE_H
#define MEMOIRE_H

#include <stdint.h>

typedef struct memoire_s {
    uint64_t id;
    char buffer[252];
} memoire_t;

memoire_t* from_fourmis_buffer(char* buffer);

#endif