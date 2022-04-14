// eratosthenes.c
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


//INCLUDE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "bitset.h"


// Eratosthenesovo síto
// Nastaví bity v poli na 0 když index bitu je prvočíslo, na 1 když index bitu není prvočíslo
// PARAMS: p - název pole bitů
void eratosthenes(bitset_t p)
{
    // Nastavení čísel 0 a 1 na 1 (není prvočíslo)
    bitset_setbit(p, 0, 1);
    bitset_setbit(p, 1, 1);
    
    for (bitset_index_t i = 2; i < sqrt(p[0]); i++)
    {
        if ((bitset_getbit(p, i)) == 0)
        {
            for (bitset_index_t j = 2*i; j < p[0]; j += i)
            {
                // Nastavení bitů násobků prvočísel na 1 (není prvočíslo)
                bitset_setbit(p, j, 1);
            }
        }
    }
}