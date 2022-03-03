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
	printf("����ߣ�");
	while (1)
	{
		printf("�������������");
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
				printf("�õ�ַ�������ӣ����������룺");
			}

		}
		else
		{
			printf("���������������������룺");
		}
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:\n");
	
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
				return 0;//����û��
			}
		}
	}
	return 1;//��������


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
	//�ж��Ƿ�ƽ��
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';//ƽ��
	}
	return 'c';//����
	
}


	



	

