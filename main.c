#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.c"
#include <errno.h>

int ncols, nlines;
int nmines;
int mines;
int nflags;
float blank_board[26][26];//tabuleiro composto por '.'s
float final_board[26][26];
char f_or_u;

void main(){
    int *line_ptr = &nlines, *col_ptr = &ncols, *mine_ptr = &nmines;
    float board[26][26]; //board inicial, os valores não vao ser alterados, este board nao é impresso
    char nliness[1000];
    printf("Bem vindo ao minesweeper!\n");
    menu();
    generate_board(board, *line_ptr, *col_ptr, *mine_ptr);
    jogada(board, *line_ptr, *col_ptr, *mine_ptr);
}
