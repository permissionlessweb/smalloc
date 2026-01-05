#include <stddef.h>
#include <stdlib.h>

extern void* smmalloc_malloc(size_t);
extern void smmalloc_free(void*);
extern void* smmalloc_realloc(void*, size_t);

typedef struct { void* replacement; void* replacee; } interpose_t;

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_malloc = { 
    (void*)smmalloc_malloc, 
    (void*)malloc 
};

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_free = { 
    (void*)smmalloc_free, 
    (void*)free 
};

__attribute__((visibility("default"), section("__DATA,__interpose")))
interpose_t interpose_realloc = { 
    (void*)smmalloc_realloc, 
    (void*)realloc 
};
