#include "htab.h"
#include "htab_structs.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        htab_item_t * item = t->arr_ptr[i];
        while (t->arr_ptr[i] != NULL)
        {
            htab_pair_t tmp = item->pair;
            f(&item->pair);
            if (strcmp(tmp.key, item->pair.key) != 0 || tmp.value != item->pair.value)
                item->pair = tmp;
            if (item->next == NULL)
                break;
            item = item->next;
        }
    }
}
