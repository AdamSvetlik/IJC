// bitset.h
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


// INCLUDE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#include "error.h"

#ifndef BITSET_H
#define BITSET_H


typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

// Inicializace bitového pole 
// PARAMS: jmeno_pole - název bitového pole
//         velikost - počet bitů v poli
#define bitset_create(jmeno_pole, velikost) static_assert(velikost > 0, "bitset_create: Velikost pole musi byt vetsi nez 0!");\
    unsigned long jmeno_pole[(((unsigned long)velikost)/(CHAR_BIT*sizeof(unsigned long))) + ((((unsigned long)velikost) % (CHAR_BIT*sizeof(unsigned long))) ? 1 : 0) + 1] = {velikost}

// Alokace paměti pro bitové pole 
// PARAMS: jmeno_pole - název bitového pole
//         velikost - počet bitů v poli
#define bitset_alloc(jmeno_pole, velikost) assert(velikost > 0);\
    unsigned long *jmeno_pole = calloc((((unsigned long)velikost)/(CHAR_BIT*sizeof(unsigned long))) + ((((unsigned long)velikost) % (CHAR_BIT*sizeof(unsigned long))) ? 1 : 0) + 1, sizeof(unsigned long));\
    if (jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace pameti");\
    *jmeno_pole = velikost;

// Užití Maker
#ifndef USE_INLINE

// Uvolnění alokované paměti bitového pole 
// PARAMS: jmeno_pole - název bitového pole
#define bitset_free(jmeno_pole) free(jmeno_pole)

// Vrací velikost bitového pole 
// PARAMS: jmeno_pole - název bitového pole
#define bitset_size(jmeno_pole) jmeno_pole[0]

// Nastavení daného bitu na danou hodnotu (0 nebo 1) 
// PARAMS: jmeno_pole - název bitového pole
//         index - index nastavovaného bitu
//         vyraz - if 0 -> nastaví hodnotu bitu na 0, if 1 -> nastaví hodnotu bitu na 1
#define bitset_setbit(jmeno_pole, index, vyraz)\
    if (index >= jmeno_pole[0])\
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long) index, (unsigned long)jmeno_pole[0] -1);\
    if (vyraz == 1)\
        jmeno_pole[(((unsigned long)index) / (CHAR_BIT * sizeof(unsigned long))) + 1] |= (((unsigned long) 1) << (((unsigned long)index) % (CHAR_BIT * sizeof(unsigned long))));\
    else\
        jmeno_pole[(((unsigned long)index) / (CHAR_BIT * sizeof(unsigned long))) + 1] &= ~(((unsigned long) 1) << (((unsigned long)index) % (CHAR_BIT * sizeof(unsigned long))))

// Vrací hodnotu daného bitu (0 nebo 1) 
// PARAMS: jmeno_pole - název bitového pole
//         index - index nastavovaného bitu
#define bitset_getbit(jmeno_pole, index)\
    index >= jmeno_pole[0] ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long) index, (unsigned long)jmeno_pole[0] -1), (unsigned long) 0) :\
    (jmeno_pole[(((unsigned long)index) / (CHAR_BIT * sizeof(unsigned long))) + 1] & ((unsigned long) 1 << (((unsigned long)index) % (CHAR_BIT * sizeof(unsigned long)))))

// Užití inline funkcí    
#else 

// Uvolnění alokované paměti bitového pole 
// PARAMS: jmeno_pole - název bitového pole
inline void bitset_free(bitset_t jmeno_pole)
{
    free(jmeno_pole);
}

// Vrací velikost bitového pole 
// PARAMS: jmeno_pole - název bitového pole
inline unsigned long bitset_size(bitset_t jmeno_pole)
{
    return jmeno_pole[0];
}

// Nastavení daného bitu na danou hodnotu (0 nebo 1) 
// PARAMS: jmeno_pole - název bitového pole
//         index - index nastavovaného bitu
//         vyraz - if 0 -> nastaví hodnotu bitu na 0, if 1 -> nastaví hodnotu bitu na 1
inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, unsigned long vyraz)
{
    if (index >= jmeno_pole[0])
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long) index, (unsigned long)jmeno_pole[0] -1);
    else
    {
        if (vyraz == 1)
        {
            jmeno_pole[(index / (CHAR_BIT * sizeof(unsigned long))) + 1] |= ((unsigned long)1 << (index % (CHAR_BIT * sizeof(unsigned long))));
        }
        else
        {
            jmeno_pole[(index / (CHAR_BIT * sizeof(unsigned long))) + 1] &= ~((unsigned long)1 << (index % (CHAR_BIT * sizeof(unsigned long))));
        }
    }
}

// Vrací hodnotu daného bitu (0 nebo 1) 
// PARAMS: jmeno_pole - název bitového pole
//         index - index nastavovaného bitu
inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
    if (index >= jmeno_pole[0])
    {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long) index, (unsigned long)jmeno_pole[0] -1);
        return 0;
    }
    else
        return jmeno_pole[(index / (CHAR_BIT * sizeof(unsigned long))) + 1] & ((unsigned long) 1 << (index % (CHAR_BIT * sizeof(unsigned long))));
}

#endif //USE_INLINE
#endif //BITSET_H