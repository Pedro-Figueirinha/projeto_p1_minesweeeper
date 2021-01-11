#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x, y;
float diff;
int ncols, nlines;
int nmines = 0;
int mines = 0;
//int board[30][30];                                      //This 2-D array contains all of the mines, numbers and blank spaces
int blank_board[30][30];                                //This contains the board full of '|-|' characters
int final_board[30][30];


void generate_board(int board[nlines][ncols],int nlines, int ncols, int nmines){

    int i = 0, j = 0;

    srand( time( NULL ) );                                  //Starts the random no. generator

    while( j < nlines )                                          //Nested loop for making the blank board and final board
    {
        while( i < ncols)
        {
            board[i][j] = '-';
            blank_board[i][j] = board[i][j];        
            final_board[i][j] = board[i][j];        
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < nmines )                            //Randomly generates the mines into the board
    {
        i = rand()%(ncols);
        j = rand()%(nlines);
        if( board[i][j] != '*')                         //If statement that checks if there is a mine already there and doesn't place a mine if there is
        {
            board[i][j] = '*';
            final_board[i][j] = board[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < nlines )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < ncols)
        {
            if( board[i][j] != '*')
            {
                board[i][j] = 0;
            }   
            if((board[i-1][j-1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i-1][j] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i][j-1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i-1][j+1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i+1][j-1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i+1][j] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i][j+1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            if((board[i+1][j+1] == '*') && (board[i][j] != '*'))
            {
                board[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    
    

}

void print_board(int board[nlines][ncols],int nlines, int ncols, int nmines){

    int i = 0, j = 0, z = 0;
    while( z < ncols )                                          // This while loop prints out the line of co-ordinates along the x axis of the minefield
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < nlines )                                          // Loop that prints out each character in the minefield                         
    {   
        printf("|%d|\t", j);
        while( i < ncols)
        {
            if( blank_board[i][j] == '-')
            {
                printf("|%c|\t", blank_board[i][j]);

            }
            else if( board[i][j] == 0 )                 // This changes any spaces with values of zero to the character 'B'
            {
                blank_board[i][j] = 'B';                
                printf("|%c|\t", blank_board[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_board[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
    
}

//int uncover(board, nlines, ncols, line, col){}

//int flag(board, nlines, ncols, line, col){}

//int game_ended(board, nlines, ncols){}

int main(){

    int board[26][26];

    printf("\t\tDimensoes do tabuleiro:\n");
    printf("\t\tcolunas:\n");
    scanf("%d", &ncols);
    printf("\t\tlinhas:\n");
    scanf("%d", &nlines);
    printf("\t\tminas\n");
    scanf("%d", &nmines);
    generate_board(board, nlines, ncols, nmines);
    print_board(board, nlines, ncols, nmines);
    return 0;

}
