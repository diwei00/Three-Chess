#include "game.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';

		}
	}
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   
void display_board(char board[ROW][COL], int row, int col)
   {
	int x = 0;
	   for (x = 0; x < row; x++)
	   {
		   int y = 0;
		   for (y = 0; y < col; y++)
		   {
			   printf(" %c ",board[x][y]);
			   if (y < col - 1)
			   {
				   printf("|");
			   }
		   }
		   printf("\n");
		   if (x < row - 1)
		   {
			   for (y = 0; y < col;y++)
			   {
				   printf("---");
				   if (y < col - 1)
				   {
					   printf("|");
				   }	    
			   }
			   printf("\n");

		   }
		  
	   }
	   

   }
void play_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：");
	while (1)
	{
		printf("请输入你的坐标");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该地址已有棋子，请重新输入：");
			}

		}
		else
		{
			printf("输入坐标有误，请重新输入：");
		}
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:\n");
	
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	

}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了


}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}

	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{

		return board[1][1];
	}
	if (board[1][1] == board[0][2] && board[0][2] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';//平局
	}
	return 'c';//继续
	
}


	



	

