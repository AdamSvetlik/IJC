#include "htab.h"
#include "htab_structs.h"

htab_item_t *htab_item_init(htab_key_t key)
{
    htab_item_t *item = malloc(sizeof(htab_item_t));
    if (item == NULL)
        return NULL;
    //item->pair.key = key;
    char * tmp = malloc(sizeof(htab_key_t) * (strlen(key) + 1));
    strcpy(tmp, key);
    item->pair.key = tmp;
    item->pair.value = 0;
    item->next = NULL;
    return item;
}