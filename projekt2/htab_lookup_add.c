#include "htab.h"
#include "htab_structs.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    htab_pair_t *pair = htab_find(t, key);
    if (pair == NULL)
    {
        if(htab_insert_item(t, key) == false)
            return NULL;
        if (t->size / t->arr_size > AVG_LEN_MAX)
            htab_resize(t, 2 * t->arr_size);
        pair = htab_find(t, key);
        return pair;
    }
    return pair;
}