// INCLUDE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"


// DEFINE
#define NUMBER_LIMIT 300000000
#define PRIME_AMOUNT 10


int main()
{
    // Inicializace timeru
    clock_t start;
    start = clock();

    // Inicializace pole
    bitset_create(pole1, NUMBER_LIMIT);

    eratosthenes(pole1);

    // Ukládání posledních 10 prvočísel
    int vysledek[PRIME_AMOUNT];
    int j = 0;
    for (bitset_index_t i = bitset_size(pole1)-1; i > 0; i--)
    {
        if (!(bitset_getbit(pole1, i)))
        {
            vysledek[j++] = i;
            if (j == PRIME_AMOUNT)
                break;
        } 
    }

    // Print na STDOUT
    for (int i = PRIME_AMOUNT-1; i >= 0; i--)
    {
        printf("%d\n", vysledek[i]);
    }

    // Print času provedení programu
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}