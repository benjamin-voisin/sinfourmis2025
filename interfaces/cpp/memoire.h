#ifndef MEMOIRE_H
#define MEMOIRE_H

#include <stdint.h>

#include "ram.h"

#define RAM_SIZE 252

typedef struct memoire_raw_s {
    uint64_t id;
    char buffer[RAM_SIZE];
} memoire_raw_t;

typedef struct memoire_s {
    memoire_raw_t* raw;
    ram_t* ram;
} memoire_t;

memoire_t* mem_alloc(char* buffer);

memoire_t* mem_free(char* buffer);

#endif