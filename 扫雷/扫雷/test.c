#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	PRINTN
	printf("--------MineSweeper--------\n");
	printf("***************************\n");
	printf("*******   1. play   *******\n");
	printf("*******   0. exit   *******\n");
	printf("***************************\n");
}

void game()
{
	// 存放地雷的数组 - root
	char mine[ROWS][COLS] = { 0 };
	// 玩家显示的数组 - user
	char show[ROWS][COLS] = { 0 };

	MineInit(mine, ROWS, COLS, '0');
	MineInit(show, ROWS, COLS, '*');

	SetMine(mine, ROW, COL);
	// 打印棋盘 - root
	PrintMine(mine, ROW, COL);
	// 打印棋盘 - user
	PrintMine(show, ROW, COL);

	MineSweeper(mine, show, ROW, COL);
	//PrintMine(show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);

	return 0;
}