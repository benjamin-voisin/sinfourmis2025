#ifndef FOURMIS_ALLOC
#define FOURMIS_ALLOC

#include "stdint.h"

typedef struct ram_s {
    char* buffer;
    uint64_t size;
} ram_t;


ram_t* ram_alloc(char* buffer, uint64_t size);
void ram_free(ram_t* ram);

#endif