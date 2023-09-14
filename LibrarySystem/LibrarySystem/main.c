#define _CRT_SECURE_NO_WARNINGS 1

#include "function.h"

int main() 
{
	int input = 0;
	printf("欢迎进入图书管理系统\n");
	in:printf("按1进入管理员系统,按2进入用户系统,按0退出系统:>");
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
		printf("退出系统~\n");
		break;
	default:
		printf("输入错误!请重新输入!\n");
		goto in;
		break;
	}
	return 0;
}


