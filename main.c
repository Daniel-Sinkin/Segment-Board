#include <stdint.h>
#include <stdio.h>

#include "boards.h"

typedef int (*board_ptr)[Y_SIZE][X_SIZE];

#define ACTIVE_CHAR '#'
#define INACTIVE_CHAR ' '

void board_print(int board[Y_SIZE][X_SIZE]) {
    printf("      12345\n");
    printf("      |||||\n");
    printf("   +--+++++--\n");
    printf("   |  \n");

    for(size_t y = 0; y < Y_SIZE; y++) {
        printf("%zu %s", y + 1, "-|  ");
        for(size_t x = 0; x < X_SIZE; x++) {
            if((y == 0 && (x == 0 || x == 4)) || (y == 4 && (x == 0 || x == 4)) || (y == 8) && (x == 0 || x == 4)) {
                printf("%c", INACTIVE_CHAR);
            } else {
                if(board[y][x] == 0) {
                    printf("%c", INACTIVE_CHAR);
                } else {
                    printf("%c", ACTIVE_CHAR);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void board_add(int board1[Y_SIZE][X_SIZE], int board2[Y_SIZE][X_SIZE]) {
    for(size_t y = 0; y < Y_SIZE; y++) {
        for(size_t x = 0; x < X_SIZE; x++) {
            if(board1[y][x] | board2[y][x]) {
                board1[y][x] = 1;
            }
        }
    }
}

void board_remove(int board1[Y_SIZE][X_SIZE], int board2[Y_SIZE][X_SIZE]) {
    for(size_t y = 0; y < Y_SIZE; y++) {
        for(size_t x = 0; x < X_SIZE; x++) {
            if(board2[y][x]) {
                board1[y][x] = 0;
            }
        }
    }
}

void board_clear(int board[Y_SIZE][X_SIZE]) {
    for(size_t y = 0; y < Y_SIZE; y++) {
        for(size_t x = 0; x < X_SIZE; x++) {
            board[y][x] = 0;
        }
    }
}

int char_to_board(char c) {
    int c_int = ((int)c) - 65;
    if((c_int >= 0) && (c_int <= 7)) {
        return c_int;
    } else {
        return -1;
    }
}

void process_board_string(int board[Y_SIZE][X_SIZE], char s[], size_t s_size, int doPrint) {
    board_ptr boards[] = {&A, &B, &C, &D, &E, &F, &G}; 

    if(doPrint == 1) {
        printf("Got input: '%s'.\n", s);
    }
    for(int i = 0; i < s_size; i++) {
        char curr = s[i];
        int curr_idx = char_to_board(curr);
        
        if(curr_idx != -1) {
            if(doPrint == 1) {
                printf("Adding Segment '%c'\n", curr);
            }
            board_add(board, *boards[curr_idx]);
        } else if(curr == '+') {
            i += 1;
            if(doPrint == 1) {
                printf("Adding Segment '%c'\n", s[i]);
            }
            board_add(board, *boards[char_to_board(s[i])]);
        } else if(curr == '-') {
            i += 1;
            if(doPrint == 1) {
                printf("Removing Segment '%c'\n", s[i]);
            }
            board_remove(board, *boards[char_to_board(s[i])]);
        } else if(curr == '~') {
            if(doPrint == 1) {
                printf("Clearing board.\n");
            }
            board_clear(board);
        }

        if((curr != '\0') && (doPrint == 1)) {
            board_print(board);
        }
    }
}

int main() {
    int board[Y_SIZE][X_SIZE];
    board_clear(board);

    char s[] = "+ACG-A~+F+A+G+B-A-F~+A";
    size_t s_size = sizeof(s) / sizeof(char);
    process_board_string(board, s, s_size, 1);

    printf("################################\n");
    printf("# STARTING TO PRINT CHARACTERS #\n");
    printf("################################\n");

    char _0[] = "ABCDEF";
    printf("Printing '0'.\n");
    process_board_string(board, _0, sizeof(_0) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _1[] = "BC";
    printf("Printing '1'.\n");
    process_board_string(board, _1, sizeof(_1) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _2[] = "ABDEG";
    printf("Printing '2'.\n");
    process_board_string(board, _2, sizeof(_2) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _3[] = "ABCDG";
    printf("Printing '3'.\n");
    process_board_string(board, _3, sizeof(_3) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _4[] = "BCFG";
    printf("Printing '4'.\n");
    process_board_string(board, _4, sizeof(_4) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _5[] = "ACDFG";
    printf("Printing '5'.\n");
    process_board_string(board, _5, sizeof(_5) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _6[] = "ACDEFG";
    printf("Printing '6'.\n");
    process_board_string(board, _6, sizeof(_6) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _7[] = "ABC";
    printf("Printing '7'.\n");
    process_board_string(board, _7, sizeof(_7) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _8[] = "ABCDEFG";
    printf("Printing '8'.\n");
    process_board_string(board, _8, sizeof(_8) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _9[] = "ABCFG";
    printf("Printing '9'.\n");
    process_board_string(board, _9, sizeof(_9) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _o[] = "CDEG";
    printf("Printing 'o'.\n");
    process_board_string(board, _o, sizeof(_o) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _b[] = "GCDEF";
    printf("Printing 'b'.\n");
    process_board_string(board, _b, sizeof(_b) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _c[] = "DEG";
    printf("Printing 'c'.\n");
    process_board_string(board, _c, sizeof(_c) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _d[] = "BCDEG";
    printf("Printing 'd'.\n");
    process_board_string(board, _d, sizeof(_d) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _E[] = "ADEFG";
    printf("Printing 'E'.\n");
    process_board_string(board, _E, sizeof(_E) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    char _F[] = "AEFG";
    printf("Printing 'F'.\n");
    process_board_string(board, _F, sizeof(_F) / sizeof(char), 0);
    board_print(board);
    board_clear(board);

    return 0;
}