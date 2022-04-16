#include "htab.h"
#include "htab_structs.h"

void htab_insert_item(htab_t * t, htab_key_t key)
{
    int hash = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = htab_item_init(key);

    htab_item_t *tmp = t->arr_ptr[hash];
    t->arr_ptr[hash] = item;
    item->next = tmp;
    t->size++;
}