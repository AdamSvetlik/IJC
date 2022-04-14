# Makefile
# Řešení IJC-DU1
# Příklad A
# Datum začátku: 26.2.2022
# Autor: Adam Světlík
# Fakulta: FIT
# Přeloženo: gcc (GCC) 7.5.0


CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2 -lm
CFLAGS-I=$(CFLAGS) -DUSE_INLINE

# Přeloží program
all: primes primes-i steg-decode

# Přeloží a spustí program na Linuxu
run: primes primes-i
	./primes
	./primes-i
	


# Překládání programu s makrelama do .o souborů
primes.o: primes.c 
	$(CC) $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o error.o

bitset.o: bitset.c
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o


# Překládání programu s mekrelama do spustitelného souboru
primes: primes.o eratosthenes.o error.o bitset.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o error.o bitset.o -o primes



# Překládání programu s inline funkcemi do .o souborů
primes-i.o: primes.c 
	$(CC) $(CFLAGS-I) -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS-I) -c eratosthenes.c -o eratosthenes-i.o

error-i.o: error.c
	$(CC) $(CFLAGS-I) -c error.c -o error-i.o

bitset-i.o: bitset.c
	$(CC) $(CFLAGS-I) -c bitset.c -o bitset-i.o


# Překládání programu s inline funkcemi do spustitelného souboru
primes-i: primes-i.o eratosthenes-i.o error-i.o bitset-i.o
	$(CC) $(CFLAGS-I) primes-i.o eratosthenes-i.o error-i.o bitset-i.o -o primes-i


# Překládání programu do .o souborů
steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o


# Překládání programu do spustitelného souboru
steg-decode: eratosthenes.o error.o steg-decode.o ppm.o
	$(CC) $(CFLAGS) ppm.o eratosthenes.o error.o bitset.o steg-decode.o -o steg-decode



# Vymaže všechny .o soubory z adresáře
clean:
	rm *.o
