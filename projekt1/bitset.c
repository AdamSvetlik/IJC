// bitset.c
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo (Merlin): gcc (GCC) 7.5.0


// INCLUDE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#include "error.h"
#include "bitset.h"

// Externí definice inline funkcí
#ifdef USE_INLINE
    extern inline void bitset_free(bitset_t jmeno_pole);
    extern inline unsigned long bitset_size(bitset_t jmeno_pole);
    extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, unsigned long vyraz);
    extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
#endif