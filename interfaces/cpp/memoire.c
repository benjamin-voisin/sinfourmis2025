#include "memoire.h"

memoire_t* mem_alloc(char* buffer) {
    memoire_t* mem = malloc(sizeof(memoire_t));
    mem->raw = buffer;
    mem->ram = ram_alloc(mem->raw->buffer, RAM_SIZE);
    return mem;
}
void mem_free(memoire_t* mem) {
    ram_free(mem->ram);
    free(mem);
}