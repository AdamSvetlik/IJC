#include "htab.h"
#include "htab_structs.h"

void htab_resize(htab_t *t, size_t newn)
{
    if (newn < 1)
    {
        fprintf(stderr, "Chyba pri zmene velikosti pole");
    }
    else
    {
        htab_pair_t backup[t->size];
        size_t backup_index = 0;
        for (size_t i = 0; i < t->arr_size; i++)
        {
            htab_item_t * item = t->arr_ptr[i];
            while (item != NULL)
            {
                //backup[backup_index++] = item->pair;
                //char * tmp = malloc(sizeof(htab_key_t) * (strlen(key) + 1));
                //strcpy(tmp, key);
                //strcpy((char *)backup[backup_index].key, item->pair.key);
                //backup[backup_index++].value = item->pair.value;
                backup[backup_index].key = malloc(strlen(item->pair.key) + 1);
                strcpy((char *)backup[backup_index].key, item->pair.key);
                backup[backup_index++].value = item->pair.value;
                item = item->next;
            }
            
        }
        htab_clear(t);
        t->arr_ptr = realloc(t->arr_ptr, newn * sizeof(htab_item_t*));
        t->arr_size = newn;
        t->size = 0;
        for (size_t i = 0; i < t->arr_size; i++)
        {
            t->arr_ptr[i] = NULL;
        }
        for (size_t i = 0; i < backup_index; i++)
        {
            htab_insert_item(t, backup[i].key);
            htab_find(t, backup[i].key)->value = backup[i].value;
        }
    }
}