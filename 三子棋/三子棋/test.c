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
	// ��ʼ������
	BoardInit(board, ROW, COL);
	// ��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		// �������
		player_move(board, ROW, COL);
		//Sleep(1000);
		system("cls");
		DisplayBoard(board, ROW, COL);
		ISWIN

		// ��������
		computer_move(board, ROW, COL);
		//Sleep(1000);
		//system("cls");
		DisplayBoard(board, ROW, COL);
		ISWIN
	}
	if (is_win(board, ROW, COL) == '*')
	{
		printf("���Ӯ��\n");
	}
	if (is_win(board, ROW, COL) == '#')
	{
		printf("����Ӯ��\n");
	}
	if (is_win(board, ROW, COL) == 'Q')
	{
		printf("ƽ��\n");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();

		printf("������ѡ��:>");
		scanf("%d", &input);
		//printf("\n");
		PRINTN
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("�������!\n");
			break;
		}
	} while (input);

	return 0;
}