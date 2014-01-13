CFLAGS=-Wall -g -std=c99 -o
CC=gcc


#DEPENDENCIES_WILDCARD=wildcards_main.c wildcards.c wildcards.h
ex_01_1_8: chapter01/exercise_1_8.c
	$(CC) $(CFLAGS) $@ $^

ex_01_1_9: chapter01/exercise_1_9.c
	$(CC) $(CFLAGS) $@ $^

ex_01_1_10: chapter01/exercise_1_10.c
	$(CC) $(CFLAGS) $@ $^

ex_01_1_12: chapter01/exercise_1_12.c
	$(CC) $(CFLAGS) $@ $^

ex_01_1_13: chapter01/exercise_1_13.c
	$(CC) $(CFLAGS) $@ $^
