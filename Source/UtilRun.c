#include "Global.h"

void *malloc(size_t size)
{
    // exit(14);
    return GlobalMalloc(size);
}

void *realloc(void *object, size_t size)
{
    return GlobalRealloc(object, size);
}

void *calloc(size_t count, size_t size)
{
    return GlobalCalloc(count, size);
}

void free(void *object)
{
    GlobalFree(object);
}
