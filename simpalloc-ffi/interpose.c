#include <stddef.h>
#include <stdlib.h>

extern void* simpalloc_malloc(size_t);
extern void simpalloc_free(void*);
extern void* simpalloc_realloc(void*, size_t);

typedef struct { void* replacement; void* replacee; } interpose_t;

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_malloc = { 
    (void*)simpalloc_malloc, 
    (void*)malloc 
};

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_free = { 
    (void*)simpalloc_free, 
    (void*)free 
};

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_realloc = { 
    (void*)simpalloc_realloc, 
    (void*)realloc 
};
