#define _CRT_SECURE_NO_WARNINGS 1

#include "function.h"

int main() 
{
	int input = 0;
	printf("��ӭ����ͼ�����ϵͳ\n");
	in:printf("��1�������Աϵͳ,��2�����û�ϵͳ,��0�˳�ϵͳ:>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		admin();
		break;
	case 2:
		user();
		break;
	case 0:
		printf("�˳�ϵͳ~\n");
		break;
	default:
		printf("�������!����������!\n");
		goto in;
		break;
	}
	return 0;
}


