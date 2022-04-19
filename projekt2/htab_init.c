#include "htab.h"
#include "htab_structs.h"


htab_t *htab_init(size_t n)
{
    if (n < 1)
        return NULL;
    htab_t *htab_table = malloc(sizeof(htab_t));
    if (htab_table == NULL)
        return NULL;
    htab_table->size = 0;
    htab_table->arr_size = n;
    htab_table->arr_ptr = malloc(n * sizeof(htab_item_t*));
    if (htab_table->arr_ptr == NULL)
        return NULL;
    for (size_t i = 0; i < n; i++)
    {
        htab_table->arr_ptr[i] = NULL;
    }
    return htab_table;
}
