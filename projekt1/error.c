// error.c
// Řešení IJC-DU1
// Příklad A
// Datum začátku: 26.2.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


//INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Varovná hláška na error
// PARAMS: fmt - řetězec zobrazený na STDERR
void warning_msg(const char *fmt, ...)
{
    va_list agrs;
    va_start(agrs, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, agrs);
    va_end(agrs);
}

// Errorová hláška vracející 1
// PARAMS: fmt - řetězec zobrazený na STDERR
void error_exit(const char *fmt, ...)
{
    va_list agrs;
    va_start(agrs, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, agrs);
    va_end(agrs);
    exit(1);
}