#include "htab.h"
#include "htab_structs.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key)
{
    int hash = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr_ptr[hash];
    while (item != NULL && strcmp(item->pair.key, key) != 0)
    {
        item = item->next;
    }
    if (item == NULL)
        return NULL;
    htab_pair_t * pair = &(item->pair);
    return pair;
}