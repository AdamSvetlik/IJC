CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra

all: wordcount_without_lib

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o tail

clean:
	rm *.o




htab_hash_function.o: htab_hash_function.c
	$(CC) $(CFLAGS) -c htab_hash_function.c -o htab_hash_function.o

htab_init.o: htab_init.c 
	$(CC) $(CFLAGS) -c htab_init.c -o htab_init.o

htab_item_init.o: htab_item_init.c 
	$(CC) $(CFLAGS) -c htab_item_init.c -o htab_item_init.o

htab_insert_item.o: htab_insert_item.c 
	$(CC) $(CFLAGS) -c htab_insert_item.c -o htab_insert_item.o

htab_erase.o: htab_erase.c 
	$(CC) $(CFLAGS) -c htab_erase.c -o htab_erase.o

htab_clear.o: htab_clear.c 
	$(CC) $(CFLAGS) -c htab_clear.c -o htab_clear.o

htab_free.o: htab_free.c 
	$(CC) $(CFLAGS) -c htab_free.c -o htab_free.o

htab_find.o: htab_find.c 
	$(CC) $(CFLAGS) -c htab_find.c -o htab_find.o

htab_for_each.o: htab_for_each.c 
	$(CC) $(CFLAGS) -c htab_for_each.c -o htab_for_each.o

htab_resize.o: htab_resize.c 
	$(CC) $(CFLAGS) -c htab_resize.c -o htab_resize.o

htab_lookup_add.o: htab_lookup_add.c 
	$(CC) $(CFLAGS) -c htab_lookup_add.c -o htab_lookup_add.o

io.o: io.c 
	$(CC) $(CFLAGS) -c io.c -o io.o

wordcount.o: wordcount.c 
	$(CC) $(CFLAGS) -c wordcount.c -o wordcount.o


libhtab.a: htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o
	ar rcs libhtab.a htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o


wordcount: io.o wordcount.o libhtab.a
	$(CC) $(CFLAGS) -o wordcount io.o wordcount.o -L. -libhtab.a

wordcount_without_lib: htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o io.o wordcount.o
	$(CC) $(CFLAGS) htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o io.o wordcount.o -o wordcount_without_lib

test_htab.o: test_htab.c
	$(CC) $(CFLAGS) -c test_htab.c -o test_htab.o

htabtest: htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o io.o test_htab.o
	$(CC) $(CFLAGS) htab_hash_function.o htab_init.o htab_item_init.o htab_insert_item.o htab_erase.o htab_clear.o htab_free.o htab_find.o htab_for_each.o htab_resize.o htab_lookup_add.o io.o test_htab.o -o htabtest