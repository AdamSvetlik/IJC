// ppm.h
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


#ifndef PPM_H
#define PPM_H

// Struktura pro ukládání hodnot pixelu z .ppm souboru
struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

// Definice funkcí
struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif