#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board(char board[ROW][COL], int row, int col);
void display_board(char board[ROW][COL], int row, int col);
void play_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL],int row,int col );
int is_full(char board[ROW][COL], int row, int col);
