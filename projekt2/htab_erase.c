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
        fprintf(stderr, "Chyba pri mazani\n");
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
    free((char *)item->pair.key);
    free(item);
    t->size--;
    //printf("ERASE: pred if resize\n");
    //print_table(t);
    if (t->size / t->arr_size < AVG_LEN_MIN && t->arr_size > 1)
    {
        //printf("ERASE: pred resize uvnitr if\n");
        //print_table(t);
        htab_resize(t, t->arr_size / 2);
        //printf("ERASE: po resize\n");
        //print_table(t);
    }
    
    /*if (t->size / t->arr_size < AVG_LEN_MIN)
    {
        htab_resize(t, t->arr_size / 2);
    }*/
    return true;
}