#include "htab.h"
#include "htab_structs.h"

bool htab_erase(htab_t * t, htab_key_t key)
{
    int hash = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr_ptr[hash];
    htab_item_t *pervious = NULL;
    while (item != NULL && strcmp(item->pair.key, key))
    {
        pervious = item;
        item = item->next;
    }
    if (item == NULL)
    {
        fprintf(stderr, "Klic nenalezen.\n");
        return false;
    }

    if (pervious == NULL)
    {
        t->arr_ptr[hash] = item->next;
    }
    else
    {
        pervious->next = item->next;
    }
    free(item);
    t->size--;
    return true;
}