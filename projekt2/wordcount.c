#include "htab.h"
#include "htab_structs.h"
#include "io.h"



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

int main()
{
    FILE *f = stdin;
    htab_t *pole = htab_init(10);
    if (pole == NULL)
    {
        fprintf(stderr, "Chyba pri alokaci pole.\n");
        return 1;
    }   
    char string[MAX_WORD_LEN + 1];

    print_table(pole);

    while (read_word(string, MAX_WORD_LEN, f) != EOF)
    {
        htab_lookup_add(pole, string)->value++;
        if (pole == NULL)
        {
            fprintf(stderr, "Chyba pri alokaci pole.\n");
            return 1;
        }
        //printf("%s\n", string);
    }

    //printf("size: %d\n", pole->size);
    //printf("arr_size: %d\n", pole->arr_size);
    print_table(pole);

    htab_erase(pole, "znaku");

    print_table(pole);
    //printf("tadyy\n");
    //printf("avg len: %d\n", pole->size / pole->arr_size);
    //if (pole->size / pole->arr_size < AVG_LEN_MIN)
    //{
        //htab_resize(pole, pole->arr_size / 2);
    //}
    //print_table(pole);
    //printf("avg len: %d\n", pole->size / pole->arr_size);
    //htab_resize(pole, pole->arr_size / 2);
    //print_table(pole);
    //printf("avg len: %d\n", pole->size / pole->arr_size);
    //htab_resize(pole, pole->arr_size * 2);
    //print_table(pole);
    htab_free(pole);

    return 0;
}