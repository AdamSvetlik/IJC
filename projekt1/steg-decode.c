// steg-decode.c
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


// INCLUDE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"
#include "ppm.h"

// DEFINE
#define MASK 0x01
#define FIRST_INDEX 29


int main(int argc, const char *argv[])
{
    if (argc != 2)
        error_exit("main: Chybny pocet argumentu.\n");

    char msg = 0x00;
    int shift = 0;

    // Inicializace struktury
    struct ppm *image = ppm_read(argv[1]);

    // Inicializace bitového pole
    bitset_alloc(prvocisla, image->xsize * image->ysize * 3);
    
    eratosthenes(prvocisla);

    // Cyklus procházející prvočísla od 29
    for (unsigned i = FIRST_INDEX; i < bitset_size(prvocisla); i++)
    {
        if (bitset_getbit(prvocisla, i) == 0)
        {
            // Ukládá LSB znaku na pozici prvočísla do msg na index 0-7 podle hodnoty shift 
            msg |= ((image->data[i] & MASK) << shift++);

            // Po uložení všech LSB do msg vytiskne znak na STDOUT 
            if (shift == 8)
            {
                printf("%c", msg);

                // Kontrola konce zašifrované zprávy
                if (msg == '\0')
                {
                    printf("\n");
                    break;
                }

                // Reset hodnot pro ukládání bitů pro další znak zprávy
                shift = 0;
                msg = 0x00;
            }
        }
    }

    // Uvolnění alokované paměti
    ppm_free(image);
    bitset_free(prvocisla);

    return 0;
}