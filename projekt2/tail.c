// tail.c
// Řešení IJC-DU2
// Příklad 1
// Datum začátku: 28.3.2022
// Autor: Adam Světlík
// Fakulta: FIT
// Přeloženo: gcc (GCC) 7.5.0


// INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// DEFINE
// MAX_LEN - určuje maxlimální délku řádku
#define MAX_LEN 4095

// Vrací posledních n řádků ze vstupu
// PARAMS: SIZE - počet tištěných posledních řádků 
//         file - stream dat (soubor nebo STDIN)
void f_tail(const int SIZE, FILE *file)
{
    // Kruhový zásobník, data se postupně přepisují po naplnění zásobníku
    char *circ_arr[SIZE];

    // Zásobník pro braní jednoho řádku ze vstupu
    char line[MAX_LEN + 3];

    // Index prvního tištěného řádku v kruhovém zásobníku
    int front = -1;

    // Index posledního tištěného řádku v kruhovém zásobníku
    int rear = -1;

    // Kontrola tisku chybového hlášení při překročení maximální délky řádku
    bool max_len_exeeded = false;

    // Využívá se při překročení maximální délky řádku pro přeskočení znaků na další řádek
    int tmp;

    // Inicializace kruhového zásobníku
    for (int i = 0; i < SIZE; i++)
    {
        circ_arr[i] = NULL;
    }

    // Čtení dat ze vstupu
    while (fgets(line, MAX_LEN + 3, file) != NULL)
    {
        // Kontrola překročení maximální délky řádku
        if (line[MAX_LEN + 1] != '\0')
        {
            // Tisk chybové hlášky při překročení maximální délky řádku
            // boolovská hodnota pro tisk chybové hlášky překročení pouze jednou
            if (max_len_exeeded == false)
            {
                max_len_exeeded = true;
                fprintf(stderr, "Maximal length of line exeeded the limit %d characters. Program will continue with shorter lines\n", MAX_LEN);
            }

            // Nastavení znaků při překročení maximální délky řádku na zkrácenou verzi
            line[MAX_LEN + 1] = '\0';
            line[MAX_LEN] = '\n';

            // Přeskočení znaků na další řádek
            while ((tmp = fgetc(file)) != '\n');
        }


        // Kontrola naplnění kruhového zásobníku

        // Kruhový zásobník je plný -> hodnoty se budou přepisovat
        if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        {
            // Posunutí indexu prvního tištěného řádku
            front = (front + 1) % SIZE;

            // Posunutí indexu posledního tištěného řádku
            rear = (rear + 1) % SIZE;

            // Alokace paměti v kruhovém zásobníku pro načtený řádek
            circ_arr[rear] = malloc(strlen(line) + 1);

            // Tisk chybové hlášky při chybné alokaci
            if (circ_arr[rear] == NULL)
            {
                fprintf(stderr, "Error: Chyba pri alokaci pameti.\n");
                exit(1);
            }

            // Kopírování řádku do kruhového zásobníku
            strcpy(circ_arr[rear], line);
        }

        // Kruhový zásobník není plný
        else 
        {
            // Nastavení indexu na 0 při prvním přiřazováním řádku do zásobníku
            if (front == -1) front = 0;

            // Posunutí indexu posledního tištěného řádku
            rear = (rear + 1) % SIZE;

            // Alokace paměti v kruhovém zásobníku pro načtený řádek
            circ_arr[rear] = malloc(strlen(line) + 1);

            // Tisk chybové hlášky při chybné alokaci
            if (circ_arr[rear] == NULL)
            {
                fprintf(stderr, "Error: Chyba pri alokaci pameti.\n");
                exit(1);
            }

            // Kopírování řádku do kruhového zásobníku
            strcpy(circ_arr[rear], line);
        }
    }

    // Tisk řádků ze zásobníku; začíná se na indexu 'front', končí se na indexu 'rear'
    for (int i = front; (i % SIZE) != rear + 1; ++i)
    {
        if (circ_arr[i % SIZE] == NULL) continue; // TODO
        printf("%s", circ_arr[i % SIZE]);
        if ((i % SIZE) == rear) break;
    }

    // Uvolnění alokované paměti v kruhovém zásobníku
    for (int i = 0; i < SIZE; i++)
    {
        free(circ_arr[i]);
    }
}


int main(const int argc, const char * argv[])
{
    // Stream dat (soubor nebo STDIN)
    FILE *file;

    // Počet tištěných posledních řádků
    int n_param;

    // Poiter potřebný při převádění řetězce na číselnou hodnotu ve funkci 'strtol'
    char *_;

    // Přepíná podle počtu argumetů
    switch (argc)
    {
    case 1: // Vstup ze STDIN bez změny počtu řádků

        // Nastavení počtu tištěnných řádků na 10
        n_param = 10;

        // Provedení funkce Tail
        f_tail(n_param, stdin);
        break;

    case 2: // Vstup ze souboru bez změny počtu řádků

        // Nastavení počtu tištěnných řádků na 10
        n_param = 10;

        // Otevření souboru
        file = fopen(argv[1], "r");

        // Tisk chybové hlášky při chýbném otevření souboru
        if (!(file))
        {
            fprintf(stderr, "Error: Chyba pri otevirani souboru.\n");
            exit(1);
        }

        // Provedení funkce Tail
        f_tail(n_param, file);

        // Zavření souboru
        fclose(file);
        break;
    
    case 3: // Vstup ze STDIN se změnou počtu řádků

        // Kontrola argumetu změny počtu řádků
        if (strcmp(argv[1], "-n") == 0)
        {
            // Převedení argumentu změny počtu řádků z řetězce na číselnou hodnotu
            n_param = strtol(argv[2], &_, 10);

            // Tisk chybové hlášky při chybně zadané hodnoty argumetu počtu řádků
            if (n_param <= 0)
            {
                fprintf(stderr, "Error: Pocet radku musi but vetsi nez 0.\n");
                exit(1);
            }

            // Provedení funkce Tail
            f_tail(n_param, stdin);
        }

        // Tisk chybové hlášky při  chybně zadaného argumetu počtu řádků
        else
        {
            fprintf(stderr, "Error: Spatne zadanu argument.\n");
            exit(1);
        }
        break;
    
    case 4: // Vstup ze souboru se změnou počtu řádků

        // Kontrola argumetu změny počtu řádků
        if (strcmp(argv[1], "-n") == 0)
        {
            // Převedení argumentu změny počtu řádků z řetězce na číselnou hodnotu
            n_param = strtol(argv[2], &_, 10);

            // Tisk chybové hlášky při chybně zadané hodnoty argumetu počtu řádků
            if (n_param <= 0)
            {
                fprintf(stderr, "Error: Pocet radku musi but vetsi nez 0.\n");
                exit(1);
            }

            // Otevření souboru
            file = fopen(argv[3], "r");

            // Tisk chybové hlášky při chýbném otevření souboru
            if (!(file))
            {
                fprintf(stderr, "Error: Chyba pri otevirani souboru.\n");
                exit(1);
            }

            // Provedení funkce Tail
            f_tail(n_param, file);

            // Zavření souboru
            fclose(file);
        }

        // Tisk chybové hlášky při  chybně zadaného argumetu počtu řádků
        else
        {
            fprintf(stderr, "Error: Spatne zadanu argument.\n");
            exit(1);
        }
        break;
    
    default: // Špatný počet argumetů
        fprintf(stderr, "Spatny pocet argumetu.\n");
        break;
    }
    return 0;
}
