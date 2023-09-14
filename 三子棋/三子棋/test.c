#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("*******   1. play   *******\n");
	printf("*******   0. exit   *******\n");
	printf("***************************\n");
	//printf("\n");
	PRINTN
}


void game()
{
	char board[ROW][COL] = { 0 };
	// 初始化棋盘
	BoardInit(board, ROW, COL);
	// 打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		// 玩家下棋
		player_move(board, ROW, COL);
		//Sleep(1000);
		system("cls");
		DisplayBoard(board, ROW, COL);
		ISWIN

		// 电脑下棋
		computer_move(board, ROW, COL);
		//Sleep(1000);
		//system("cls");
		DisplayBoard(board, ROW, COL);
		ISWIN
	}
	if (is_win(board, ROW, COL) == '*')
	{
		printf("玩家赢了\n");
	}
	if (is_win(board, ROW, COL) == '#')
	{
		printf("电脑赢了\n");
	}
	if (is_win(board, ROW, COL) == 'Q')
	{
		printf("平局\n");
	}
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
		//printf("\n");
		PRINTN
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (input);

	return 0;
}