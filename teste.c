#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>



int main(){
    int ncols, nlines;
    int nmines;
    int x;
    char y;
    int line_count=0;
    char pumbas;
    FILE *fptr = fopen("board442.txt", "r");
    char nliness[1000];
    if (fptr == NULL)
    {
        printf("Error! opening file");
    }
    fscanf(fptr, "%d %d %d", &nlines, &ncols, &nmines);    
    printf("outputs.");
    printf("\nlinhas:%d\n col:%d\n minas:%d\n", nlines, ncols, nmines);
    

    //lugar das minas
    fscanf(fptr, "%d %c", &x, &y);
    printf("x position: %d\ny position: %c\n", x, y);
    fclose(fptr);
    return 0;


}
