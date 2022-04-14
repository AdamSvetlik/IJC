// ppm.c
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


//INCLUDE
#include <stdio.h>

#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"
#include "ppm.h"

//DEFINE
#define SIZE_LIMIT 8000*8000*3
#define COLOR_LIMIT 255
#define FILE_SUFFIX ".ppm"


// Čte data ze souboru a vrací data ve struktuře ppm
// PARAMS: filename - název souboru
struct ppm * ppm_read(const char * filename)
{
    FILE *file;
    char buffer[3];
    unsigned color;
    unsigned size_x;
    unsigned size_y;

    // Otevření souboru v režimu 'read binary'
    file = fopen(filename, "rb");

    // Kontrola správnosti cesty k souboru
    if (!file)
        error_exit("ppm_read: Chyba pri otevirani souboru '%s'\n", filename);

    // Kontrola koncovky souboru - musí být '.ppm'
    const char *file_suffix = &filename[strlen(filename)-4];
    if ((strcmp(file_suffix, FILE_SUFFIX)))
    {
        fclose(file);
        error_exit("ppm_read: Spatny format souboru '%s', musi byt '.ppm'\n", filename);
    }

    // Kontrola neprázdnosti souboru
    if (!fgets(buffer,sizeof(buffer), file))
    {
        fclose(file);
        error_exit("ppm_read: Soubor '%s' je prazdny.\n", filename);
    }

    // Kontrola správnosti PPM formátu - musí být P6
    if ( buffer[0] != 'P' || buffer[1] != '6')
    {
        fclose(file);
        error_exit("ppm_read: Spatny format obrazku, musi byt typu 'P6'\n");
    }
    
    // Kontrola správnosti rozměrů obrázku
    if (fscanf(file, "%u %u", &size_x, &size_y) != 2)
    {
        fclose(file);
        error_exit("ppm_read: Chybna velikost obrazku '%s'\n", filename);
    }

    // Kontrola limitu velikosti obrázku
    if ((size_x * size_y * 3) > SIZE_LIMIT)
    {
        fclose(file);
        warning_msg("ppm_read: Velikost obrazku je vetsi nez pevne stanoveny limit (8000*8000).\n");
    }
    
    // Kontrola hodnoty barev
    if (fscanf(file, "%u", &color) != 1)
    {
        fclose(file);
        error_exit("ppm_read: Chybi komponenta barev v '%s', spatne formatovany soubor.\n", filename);
    }

    // Kontrola barevnosti obrázku
    if (color > COLOR_LIMIT)
    {
        fclose(file);
        warning_msg("ppm_read: Spatne zadana barevnost obrazku (musi byt v rozsahu 0-255).\n");
    }
    
    // Přeskočí '\n' pro následné čtení chtěných dat 
    while (fgetc(file) != '\n');

    // Alokace paměti
    struct ppm *img = (struct ppm *)malloc(sizeof(struct ppm) + (3 * size_x * size_y));

    // Vložení hodnot rozměru do struktury
    img->xsize = size_x;
    img->ysize = size_y;
    
    // Kontrola alokace paměti
    if (!img)
    {
        fclose(file);
        error_exit("ppm_read: Chyba pri allokaci pameti.");
    }

    // Kontrola čtení dat pixelu ze souboru
    if (fread(img->data, 3 * img->xsize, img->ysize, file) != img->ysize)
    {
        fclose(file);
        ppm_free(img);
        error_exit("ppm_read: Chyba pri nacitani obrazku '%s'", filename);
    }

    fclose(file);
    return img;
}

// Uvolňuje pamět struktury ppm
// PARAMS: p - název struktury ppm
void ppm_free(struct ppm *p)
{
    free(p);
}
