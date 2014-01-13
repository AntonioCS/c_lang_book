/*
 * File:   exercise_1_10.c
 * Author: antoniocs
 *
 * Created on 07 January 2014, 13:11
 * Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each
        backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
        unambiguous way

 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char **argv) {

    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("\\n");
        }
        else if (c == '\b') {
            printf("\\b");
        }
        else if (c == '\t') {
            printf("\\t");
        }
        else if (c == '\\') {
            printf("\\\\");
        }
        else {
           printf("%c",c);
        }
    }
}
