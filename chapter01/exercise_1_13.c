/*
 * File:   exercise_1_13.c
 * Author: antoniocs
 *
 * Created on 08 January 2014, 13:14
 * Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

 */

#include <stdio.h>
#include <stdlib.h>


#define IN 1
#define OUT 0
#define MAXBUFFER 500

//graph stuff
#define SPACE 32
#define SIDE_BARS '|'
#define EXTRA_COLS_FOR_BARS 2
#define EXTRA_ROWS 2


/**
 * Array in the format
 * key,value,key,value,...
 *
 * @param data
 */
void create_graph(int data[]) {

    //int scale = 15;
    int scale = 2;
    int largest = 0;
    int size = 0;
    int space_between_bars = 1;
    int bar_size = 2;

    /* Vertical graph - Work in progress
    for (int x = 1; data[x] != 0; x += 2) {
        size++;
        if (data[x] > largest) {
            largest = data[x];
        }
    }
    printf("size: %d\n",size);

    //The 2 is for the first line where the totals will be and the for the last line where the numbers will be
    int total_size_h = scale + EXTRA_ROWS;

    //The 2 is for the vertical bars at the start and end of the graph
    int total_size_w = size * (EXTRA_COLS_FOR_BARS + space_between_bars + bar_size);

    printf("total_size_w: %d\n",total_size_w);

    char graph[total_size_h][total_size_w];
    char c = SPACE;

    //initialize the array with a space
    for (int x = 0; x < total_size_h; x++) {
        for (int n = 0; n < total_size_w; n++) {
            if (x == total_size_h - 1) {
                c = 'N';
            } else if (n == 0 || n == (total_size_w - 1)) {
                c = SIDE_BARS;
            } else if (x == (total_size_h - 2)) {
                c = '_';
            } else {
                c = SPACE;
            }

            graph[x][n] = c;
        }
    }

    //show graph
    for (int x = 0; x < total_size_h; x++) {
        for (int n = 0; n < total_size_w; n++) {
            printf("%c", graph[x][n]);
        }
        printf("\n");
    }
     *
     */

    int result = 0;
    for (int i = 0;data[i] != 0;i +=2) {
        printf("%d ",data[i]);
        result = data[i+1]/scale;

        //printf("-- %d -- \n", result);
        for (int n = 0;n<=result;n++) {
            printf("#");
        }
        printf(" %d\n",data[i+1]);
    }
}

/* count lines, words, and characters in input */
int main() {

    char c;
    int state;

    int word_sizes_counts[MAXBUFFER] = {0};
    int word_sizes[MAXBUFFER] = {0};



    int word_start = 0;
    int current_word = 0;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (word_start >= MAXBUFFER) {
            printf("Too many words\n");
            exit(-1);
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            if (current_word != 0) {
                word_sizes[word_start++] = current_word;
            }

            current_word = 0;
            state = OUT;
        } else if (state == OUT) {
            current_word = 1;
            state = IN;
        } else if (state == IN) {
            current_word++;
        }
    }

    //count times numbers appear
    int x = 0;
    for (int i = 0; i < word_start; i++) {

        if (word_sizes[i] == 0)
            continue;

        word_sizes_counts[x++] = word_sizes[i];
        word_sizes_counts[x] = 1;


        for (int z = i + 1; z < word_start; z++) {
            if (word_sizes[i] == word_sizes[z]) {
                word_sizes_counts[x]++;
                word_sizes[z] = 0;
            }
        }

        x++;
    }


    for (x = 0; word_sizes_counts[x] != 0; x += 2) {
        printf("Words of length %d occurred %d times\n", word_sizes_counts[x], word_sizes_counts[x + 1]);
    }

    create_graph(word_sizes_counts);
}