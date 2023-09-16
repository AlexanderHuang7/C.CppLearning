#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// 初始化
void MineInit(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}


void PrintMine(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	PRINTN
}


void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = MINENUM;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}


static int MineNumber(char mine[ROWS][COLS], int x, int y)
{
	return
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][x - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void MineSweeper(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINENUM)
	{
		int count = 0;
		printf("请输入坐标(x,y范围均是1~%d):>", row);
		scanf("%d %d", &x, &y);
		PRINTN
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("被炸死了\n");
				PrintMine(mine, row, col);
				printf("1为雷,0为非雷\n");
				break;
			}
			else
			{
				count = MineNumber(mine, x, y);
				show[x][y] = count + '0';
				system("cls");
				//PrintMine(mine, row, col);
				PrintMine(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入错误!重新输入!\n");
		}
	}
	if (win == row * col - MINENUM)
	{
		printf("排雷成功\n");
		PrintMine(mine, row, col);
		printf("1为雷,0为非雷\n");
	}
}