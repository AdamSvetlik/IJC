CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra

all: htab_hash_function.c htab_init.c htab_item_init.c htab_insert_item.c htab_erase.c htab_clear.c htab_free.c htab_find.c htab_for_each.c htab_resize.c htab_lookup_add.c io.c wordcount.c
	$(CC) $(CFLAGS) htab_hash_function.c htab_init.c htab_item_init.c htab_insert_item.c htab_erase.c htab_clear.c htab_free.c htab_find.c htab_for_each.c htab_resize.c htab_lookup_add.c io.c wordcount.c -o testing


# added: clear, free, for_each resize lookup_add
# bug: for_each - osetrit spatnou fci