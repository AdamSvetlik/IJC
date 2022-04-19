#include "htab.h"
#include "htab_structs.h"

void print_table(htab_t *t){
    printf("Start of htab\n");
    for(int i = 0; i < (int)t->arr_size; i++){
        if (t->arr_ptr[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t ", i);
            htab_item_t *tmp = t->arr_ptr[i];
            while(tmp != NULL){
                printf("[%s, %d] - ", tmp->pair.key, tmp->pair.value);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End of htab\n");
}


void print_pair(htab_pair_t *p){
    printf("Start of pair\n");
    printf("\tKey: %s\n", p->key);
    printf("\tValue: %i\n", p->value);
    printf("End of pair\n");
}

int main(void)
{
    htab_t *p = htab_init(10);

    htab_insert_item(p, "klic");
    htab_insert_item(p, "klicek");
    htab_insert_item(p, "klic2");

    print_table(p);

    htab_find(p, "klic")->value = 5;
    htab_find(p, "klicek")->value = 15;
    htab_find(p, "klic2")->value = -3;

    print_table(p);


    //htab_erase(p, "klic");
    //print_table(p);

    //print_pair(htab_find(p, "klicek"));

    htab_for_each(p, &print_pair);

    //print_pair(htab_lookup_add(p, "klic"));
    //print_table(p);

    //print_pair(htab_lookup_add(p, "klic3"));
    //print_table(p);
    //htab_clear(p);
    //htab_resize(p, 5);
    //htab_erase(p, "klicek");
    //print_table(p);


    htab_free(p);
    //print_table(p);

}