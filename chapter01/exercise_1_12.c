/*
 * File:   exercise_1_12.c
 * Author: antoniocs
 *
 * Created on 07 January 2014, 13:19
 * Exercise 1-12. Write a program that prints its input one word per line.

 */

#include <stdio.h>
#include <stdlib.h>


#define IN 1
#define OUT 0

/* inside a word */
/* outside a word */

/* count lines, words, and characters in input */
int main() {

    char c;
    int nw, state;

    state = OUT;
    nw =0;

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            if (nw != 0) {
                putchar('\n');
            }

            putchar(c);
            state = IN;
            ++nw;
        }
        else if (state == IN) {
            putchar(c);
        }
    }
    putchar('\n');
}

