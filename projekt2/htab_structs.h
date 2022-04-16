#ifndef __HTAB_STRUCTS_H__
#define __HTAB_STRUCTS_H__

#include "htab.h"


struct htab_item
{
    htab_pair_t pair;
    htab_item_t *next;
};

// Tabulka:
struct htab    // neúplná deklarace struktury - uživatel nevidí obsah
{
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};

#endif // __HTAB_STRUCTS_H__