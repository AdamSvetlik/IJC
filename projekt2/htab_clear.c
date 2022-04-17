#include "htab.h"
#include "htab_structs.h"

void htab_clear(htab_t * t)
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        while (t->arr_ptr[i] != NULL)
        {
            htab_item_t *item = t->arr_ptr[i]->next;
            if (!(htab_erase(t, t->arr_ptr[i]->pair.key)))
                fprintf(stderr, "Chyba pri mazani\n");
            t->arr_ptr[i] = item;
        }
        //t->arr_ptr[i] = NULL;
    }
    t->size = 0;
}