#include "htab.h"
#include "htab_structs.h"

void htab_clear(htab_t * t)
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        size_t size = t->arr_size;
        htab_item_t *item = t->arr_ptr[i];
        while (item != NULL)
        {
            htab_erase(t, item->pair.key);
                //fprintf(stderr, "Chyba pri mazani\n");
            //t->arr_ptr[i] = item;
            item = item->next;
        }
        if (size != t->arr_size)
        {
            i = -1;
            size = t->arr_size;
        }
    }
    t->size = 0;
}
