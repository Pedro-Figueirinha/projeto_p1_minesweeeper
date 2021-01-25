#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x, y;
float diff;
int ncols, nlines;
int nmines = 0;
int mines = 0;
int blank_board[30][30];//tabuleiro composto por '-'s
int final_board[30][30];
char f_or_u;

void win( void )
{
    printf("\n\n\n\t\t\tGanhou!!!!!\n\n\n");
    exit(1);
}
void print_final_board(int board[nlines][ncols],int nlines, int ncols, int nmines)//Prints the minefield, showing where all of the mines are placed
{
    int i = 0, j = 0, z = 0;
    while( z < ncols )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < nlines )
    {   
        printf("|%d|\t", j);
        while( i < ncols)
        {
            printf("|%c|\t", final_board[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}
void boom( void )                    
{
    //print_final_board(board, nlines, ncols, nmines);
    printf("\n\t\tAcertou numa mina em %d,%d\n\t\tperdeu o jogo!!!!", x, y);
    exit(1);
}

void generate_board(int board[nlines][ncols],int nlines, int ncols, int nmines){

    int i = 0, j = 0;

    srand( time( NULL ) );//a utilizacao do time serve para que cada vez que o programa é corrido a posição é diferente

    for (int j=0; j < nlines; j++)//ciclo para criar o blank_board e o final_board
    {
        for (int i=0; i < ncols; i++)
        {
            board[i][j] = '-';
            blank_board[i][j] = board[i][j];        
            final_board[i][j] = board[i][j];
        }        
    }
    
    mines = 0;    
    while( mines < nmines )//minas espalhadas aleatoreamente pelo board
    {
        i = rand()%(ncols);
        j = rand()%(nlines);
        if( board[i][j] != '*')//verifica se já se existem minas naquela posição e se não, coloca lá um.
        {
            board[i][j] = '*';
            final_board[i][j] = board[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    for (int j = 0; j < nlines; j++)
    {
        for (int i = 0; i < ncols; i++)
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
        }
        
    }
    i = 0;
    j = 0;
}

void print_board(int board[nlines][ncols],int nlines, int ncols, int nmines){

    int i = 0, j = 0, z = 0;
    while( z < ncols )//print das coordenadas no topo da tabela
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < nlines )// Loop that prints out each character in the board
    {   
        printf("|%d|\t", j);
        while( i < ncols)
        {
            if( blank_board[i][j] == '-')
            {
                printf("|%c|\t", blank_board[i][j]);

            }
            else if( board[i][j] == 0 )//células vazias ' '
            {
                blank_board[i][j] = ' ';                
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
void uncover(int board[nlines][ncols],int nlines, int ncols, int nmines){

    int q = 0, i=0, j=0, match=0;
    print_board(board, nlines, ncols, nmines);
    while( j < nlines )// While loop for testing whether or not the user has cleared the board
    {
        while( i < ncols )
        {
            if(board[i][j] == blank_board[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( ncols * nlines ) - nmines))// If the user has cleared the board, the win() function is run
    {
        win();
    }
    printf("\nInsira o num da coluna, seguido de um espaço e do num da linha:");
    scanf("%d %d", &x, &y);// Reading in the co-ordinates for the guess
    if( (x >= ncols) || (x < 0) || (y < 0) || (y >= nlines) )
    {
        printf("\nInsira um valor que pertença à tabela\n");
        uncover(board, nlines, ncols, nmines);
    }
    if( board[x][y] == '*' )// Runs the boom() function if the user selects a mine
    {
        boom();
    }
    if( blank_board[x][y] != '-' )
    {
        printf("\nPosicao ja inserida. Escolha outra posicao.\n");
        uncover(board, nlines, ncols, nmines);
    }

    else// Checks if the adjacent spaces are blank, then changes the values in the blank_board array. Because they are changed, they will now print out in the print_board function
    {
        blank_board[x][y] = board[x][y];
        if( board[x][y] == 0 )
        {
            if( board[x-1][y-1] == 0 )
            {
                blank_board[x-1][y] = board[x-1][y];
            }
            if( board[x-1][y] == 0 )
            {
                blank_board[x-1][y] = board[x-1][y];
            }
            if( board[x][y-1] == 0 )
            {
                blank_board[x][y-1] = board[x][y-1];
            }
            if( board[x-1][y+1] == 0 )
            {
                blank_board[x-1][y+1] = board[x-1][y+1];
            }
            if( board[x+1][y-1] == 0 )
            {
                blank_board[x+1][y-1] = board[x+1][y-1];
            }
            if( board[x+1][y] == 0 )
            {
                blank_board[x+1][y] = board[x+1][y];
            }
            if( board[x][y+1] == 0 )
            {
                blank_board[x][y+1] = board[x][y+1];
            }
            if( board[x+1][y+1] == 0 )
            {
                blank_board[x+1][y+1] = board[x+1][y+1];
            }
        }
        uncover(board, nlines, ncols, nmines);
    }
}


int flag(board, nlines, ncols, line, col){

    


}

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
    printf("uncover ou flag? (u/f)");
    scanf("%d", &f_or_u);
    generate_board(board, nlines, ncols, nmines);
    if (f_or_u == 'u')
    {
        uncover(board, nlines, ncols, nmines);
    }
    else
    {
        flag(board, nlines, ncols, nmines);
    }
    
    
    
    
    return 0;
}
