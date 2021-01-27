#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"
#include <ctype.h>
#include <wchar.h>

int ncols, nlines;
int nmines;
int nflags;
int mines;
float blank_board[26][26];//tabuleiro composto por '.'s -> vao ser atribuidos e modificados valores neste
float final_board[26][26];
char f_or_u;

void menu(){

    int escolha;
    FILE *fptr = fopen("board442.txt", "r");
    char nliness[1000];
    printf("Escolha a sua op%c%co", 135, 198);
    printf("\n0 - Sair!\n1 - Criar tabuleiro;\n2 - Ler tabuleiro a partir de um ficheiro.");
    scanf("%d", &escolha);
    if (escolha == 0)
    {
        exit(1);
    }
    else if (escolha == 1)
    {
        printf("\t\tDimens%ces do tabuleiro:\n", 228);
        printf("linhas:\n");
        scanf("%d", &nlines);
        printf("colunas:\n");
        scanf("%d", &ncols);
        printf("minas:\n");
        scanf("%d", &nmines);      
    }
    else if (escolha == 2)
    {
        if (fptr == NULL)
        {
            printf("Error! opening file");
        }
        fscanf(fptr, "%d %d %d", &nlines, &ncols, &nmines);
        printf("outputs.");
        printf("\nlinhas:%d\n col:%d\n minas:%d\n", nlines, ncols, nmines);
        fclose(fptr);

        nflags = nmines;
        if (nlines > 26 || ncols > 26)
        {
            printf("Os valores inseridos excedem os valores poss%cveis. valor max de linhas e colunas = 26.", 161);
            exit(1);
        }
    }
    else
    {
        printf("op%c%co inválida", 135, 198);
        exit(1);
    }
}


//void jogada(float board[26][26],int nlines, int ncols, int nmines);
void generate_board(float board[26][26],int nlines, int ncols, int nmines){

    int x;
    char y;
    srand( time( NULL ) );//a utilizacao do time serve para que cada vez que o programa é corrido a posição é diferente
    //////////////////////////CENAS PARA FILES///////////////////////////////////////////////////////
    /*int a,b,c;
    FILE *fptr = fopen("board442.txt", "r");
    char nliness[1000];
    if (fptr == NULL)
    {
        printf("Error! opening file");
    }
    fscanf(fptr, "%d %d %d", &a, &b, &c);    
    printf("outputs.");
    printf("\nlinhas:%d\n col:%d\n minas:%d\n", a, b, c);*/
    /////////////////////////////////////////////////////////////////////////////////////////////////


    //lugar das minas
    char lcol, upper_lcol;
    int i, j;
    for (int i = 0; i < nlines; i++)//ciclo para criar o blank_board e o final_board
    {
        for (int j = 0; j < ncols; j++)
        {
            board[i][j] = 100;
            blank_board[i][j] = board[i][j];        
            final_board[i][j] = board[i][j];
        }        
    }
    mines = 0;
    while (mines < nmines) //minas espalhadas aleatoreamente pelo board
    {

        //////////////////////////CENAS PARA FILES///////////////////////////////////////////////////////
        /*fscanf(fptr, "%d %c", &i, &lcol);
        printf("x position: %d\ny position: %c\n", i, lcol);*/
        /////////////////////////////////////////////////////////////////////////////////////////////////


        j=0;

        //////////////////////////CENAS PARA FILES///////////////////////////////////////////////////////
        /*upper_lcol = toupper(lcol);
        for (char  letras = 'A'; letras != upper_lcol; letras++) //conversao letras para nums
        {
            j++;
        }*/
        /////////////////////////////////////////////////////////////////////////////////////////////////


        j = rand()%(ncols);
        i = rand()%(nlines);
        if( board[i][j] != -1)//verifica se já se existem minas naquela posição e se não, coloca lá um.
        {
            board[i][j] = -1;
            final_board[i][j] = board[i][j];
            mines++;
        }
    }


    //////////////////////////CENAS PARA FILES///////////////////////////////////////////////////////
    //fclose(fptr);
    /////////////////////////////////////////////////////////////////////////////////////////////////


    i = 0;
    j = 0;
    //endof lugar das minas

    for (i = 0; i < nlines; i++)
    {
        for (j = 0; j < ncols; j++)
        {
            if( board[i][j] != -1)
            {
                board[i][j] = 0;
            }   
            if((board[i-1][j-1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i-1][j] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i][j-1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i-1][j+1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i+1][j-1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i+1][j] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i][j+1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            if((board[i+1][j+1] == -1) && (board[i][j] != -1))
            {
                board[i][j]++;
            }
            printf(" %.0f", board[i][j]);
        }
        
    printf("\n");
    }
    i = 0;
    j = 0;

}
void print_board(float board[26][26],int nlines, int ncols, int nmines){

    char letras = 'A';
    int i = 0, j = 0;
    printf("|  |");
    for (i = 0; i < ncols; i++)
    {
        printf("|%c|", letras);
        letras++;
    }
    printf("\n");
    i = 0;
    for (i = 0; i < nlines; i++)// Loop that prints out each character in the board
    {
        if(i<=9)
        {
            printf("|0%d|", i);
        }
        else
        {
            printf("|%d|", i);
        }
        for (j = 0; j < ncols; j++)
        {
            if( blank_board[i][j] == 100)
            {
                printf("|.|");

            }
            else if(blank_board[i][j] == 0 )//células vazias ' '
            {                               
                printf("| |");
            }
            else if(blank_board[i][j] == -2){

                //para as flags
                printf("|f|");
            }
            else if (blank_board[i][j] == -1)
            {
                printf("|*|");
                

            }
            else //num das celulas com minas próximas
            {
               printf("|%.0f|", board[i][j]);
            }
        }
        printf("\n");
        j = 0;
    }   
}
int uncover(float board[26][26],int nlines, int ncols, int x, int y){

    if( blank_board[x][y]!= 100 && blank_board[x][y]!=-2 )
    {
        return 0;
    }
    else //limpeza das células vazias adjacentes
    {
        blank_board[x][y] = board[x][y];
        if( board[x][y] == 0 )
        {
            if( board[x-1][y-1] != 0 && board[x-1][y-1] != -1 && blank_board[x-1][y-1] != -2 )
            {
               blank_board[x-1][y-1] = board[x-1][y-1];
            }
            if( board[x-1][y] != 0 && board[x-1][y] != -1 && blank_board[x-1][y] != -2 )
            {
               blank_board[x-1][y] = board[x-1][y];
            }
            if( board[x][y-1] != 0 && board[x][y-1] != -1 && blank_board[x][y-1] != -2 )
            {
               blank_board[x][y-1] = board[x][y-1];
            }
            if( board[x-1][y+1] != 0 && board[x-1][y+1] != -1 && blank_board[x-1][y+1] != -2 )
            {
               blank_board[x-1][y+1] = board[x-1][y+1];
            }
            if( board[x+1][y-1] != 0 && board[x+1][y-1] != -1 && blank_board[x+1][y-1] != -2 )
            {
               blank_board[x+1][y-1] = board[x+1][y-1];
            }
            if( board[x+1][y] != 0 && board[x+1][y] != -1 && blank_board[x+1][y] != -2 )
            {
               blank_board[x+1][y] = board[x+1][y];
            }
            if( board[x][y+1] != 0 && board[x][y+1] != -1  && blank_board[x][y+1] != -2)
            {
               blank_board[x][y+1] = board[x][y+1];
            }
            if( board[x+1][y+1] != 0 && board[x+1][y+1] != -1 && blank_board[x+1][y+1] != -2 )
            {
               blank_board[x+1][y+1] = board[x+1][y+1];
            }
            if( board[x-1][y-1] == 0  && blank_board[x-1][y-1] != -2 )
            {
                uncover(board,nlines,ncols,x-1,y-1); 
            }
            if( board[x-1][y] == 0 &&blank_board[x-1][y] != -2)   
            {
                uncover(board,nlines,ncols,x-1,y);
            }
            if( board[x][y-1] == 0 && blank_board[x][y-1] != -2)
            {
                uncover(board,nlines,ncols,x,y-1);
            }
            if( board[x-1][y+1] == 0 && blank_board[x-1][y+1] != -2)
            {
                uncover(board,nlines,ncols,x-1,y+1);
            }
            if( board[x+1][y-1] == 0 && blank_board[x+1][y-1] != -2)
            {
                uncover(board,nlines,ncols,x+1,y-1);
            }
            if( board[x+1][y] == 0 && blank_board[x+1][y] != -2 )
            {
                uncover(board,nlines,ncols,x+1,y);
            }
            if( board[x][y+1] == 0 && blank_board[x][y+1] != -2)
            {
                uncover(board,nlines,ncols,x,y+1);
            }
            if( board[x+1][y+1] == 0 && blank_board[x+1][y+1] != -2)
            {
                uncover(board,nlines,ncols,x+1,y+1);
            }
        }   
        jogada(board, nlines, ncols, nmines);
    }
}
void win( void )
{
    printf("\n\n\n\t\t\tGanhou!!!!!\n\n\n");
    exit(1);
}
void print_final_board(float board[26][26],int nlines, int ncols)//Nao funfa
{
    int i, j;
    for (int i = 0; i < nlines; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            if (board[i][j] == -1)
            {
                blank_board[i][j] = -1;
            }            
        }        
    }
    print_board(board, nlines, ncols, nmines);
}
void boom(float board[26][26],int nlines,int ncols, int x, char y )
{    
    print_final_board(board,nlines, ncols);
    printf("\n\t\tAcertou numa mina em %d,%c\n\t\tperdeu o jogo!!!!", x, toupper(y));
    exit(1);
}
int flag(float board[26][26],int nlines, int ncols, int x, int y){

    if(blank_board[x][y] == -2)//para fazer unflag
    {
        blank_board[x][y] = 100;
        nflags++;
        jogada(board, nlines, ncols, nmines);
    }
    if(blank_board[x][y] == 100 || blank_board[x][y] == -1)//marcar a flag
    {
        blank_board[x][y] = -2;
        nflags--;
        jogada(board, nlines, ncols, nmines);
    }
}
int game_ended(float board[26][26], int nlines,int ncols)
{
    int i, j, match=0;
    for (i = 0; i < nlines; i++) //loop a verificar se o utilizador limpou o board
    {
        for (j = 0; j < ncols; j++)
        {
            if(board[i][j] == blank_board[i][j])
            {
                match++;
            }
        }
    }
    if( match == (( ncols * nlines ) - nmines))// ganhou o jogo
    {
        win();
    }
    
}
void jogada(float board[26][26],int nlines, int ncols, int nmines){
    int i=0, j=0, match=0, x, y;
    char lcol, upper_lcol;
    print_board(board, nlines, ncols, nmines);
    printf("\nnum of flags: %d", nflags);
    game_ended(board, nlines, ncols);
    printf("\nInsira o num da linha, seguido de um espaço e do num da coluna:");
    scanf("%d %c", &x, &lcol);//coordenadas 
    printf("uncover ou flag? (u/f)");
    scanf("%s", &f_or_u);
    y=0;
    upper_lcol = toupper(lcol);
    for (char  letras = 'A'; letras != upper_lcol; letras++) //conversao letras para nums
    {
        y++;
    }    
    if( (x >= nlines) || (x < 0) || (y < 0) || (y >= ncols) )
    {
        printf("\nInsira um valor que pertença à tabela\n");
        jogada(board, nlines, ncols, nmines);
    }
    else if(board[x][y] == -1 && f_or_u == 'u')
    {
        boom(board, nlines, ncols,x,lcol);
    }
    else if(blank_board[x][y] != -2 && blank_board[x][y] != 100)
    {
        printf("\nPosicao ja inserida. Escolha outra posicao.\n");
        jogada(board, nlines, ncols, nmines);
    }
    else
    {
        if (f_or_u == 'u')
        {
            uncover(board, nlines, ncols, x,y);
        }
        else if (f_or_u == 'f')
        {
            flag(board, nlines, ncols, x, y);
        }
    }
}