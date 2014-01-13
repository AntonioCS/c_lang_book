/*
 * File:   exercise_1_8.c
 * Author: antoniocs
 *
 * Created on 06 January 2014, 13:16
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int blanks;
    int tabs;
    int newlines;
} filecounts;

const filecounts defaults = { 0, 0 ,0 };


int main(int argc, char **argv) {

    filecounts f = defaults;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            f.newlines++;
        }
        else if (c == ' ') {
            f.blanks++;
        }
        else if (c == '\t') {
            f.tabs++;
        }
    }

    printf("Newlines: %d\nBlanks: %d\nTabs: %d\n",f.newlines,f.blanks,f.tabs);

}

