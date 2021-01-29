void jogada(float board[26][26],int nlines, int ncols, int nmines);
void win( void );
void boom(float board[26][26],int nlines, int ncols, int x, char y );
void print_final_board(float board[26][26],int nlines, int ncols);
void generate_board(float board[26][26],int nlines, int ncols, int nmines);
void print_board(float board[26][26],int nlines, int ncols, int nmines);
int uncover(float board[26][26],int nlines, int ncols, int x, int y);
int flag(float board[26][26],int nlines, int ncols, int x, int y);
void menu();