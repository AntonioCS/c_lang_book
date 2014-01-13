/*
 * File:   chapter_1_9.c
 * Author: antoniocs
 *
 * Created on 06 January 2014, 13:31
 * Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char **argv) {

    char c;
    short int x = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (x) {
                continue;
            }
            else {
                x = 1;
            }
        }
        else {
            x = 0;
        }

        printf("%c",c);
    }
}

