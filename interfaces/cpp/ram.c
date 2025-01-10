#include "ram.h"

ram_t* ram_alloc(char* buffer, uint64_t size) {
    ram_t* ram = malloc(sizeof(ram_t));
    ram->size = size;
    ram->buffer = buffer;
}

void ram_free(ram_t* ram) {
    free(ram);
}