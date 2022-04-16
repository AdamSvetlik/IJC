#include "htab.h"
#include "htab_structs.h"


size_t htab_size(const htab_t * t)
{
    return t->size;
}