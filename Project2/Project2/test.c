#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 11; i++)
//	{
//		arr[i] = 0;
//		printf("%d\n", i);
//	}
//
//	return 0;
//}

// 自主实现strcpy - 拷贝数组
//#include<assert.h>
//char * my_strcpy(char* dest, const char* str)
//{
//	assert(dest != NULL);// 断言
//	assert(str != NULL);// 断言
//	char* ret = dest;
//
//	while (*dest++ = *str++)
//	{
//		;
//	}
//
//	return ret;
//
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxx";
//	char arr2[] = "Hello";
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//
//	return 0;
//}

// 自主实现strlen - 计算数组长度
//#include<assert.h>
////size_t - unsigned int
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	assert(str != NULL);
//	while ( *str++ )
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "0123";
//
//	printf("字符串的长度为: %d\n", my_strlen(arr));
//
//	return 0;
//}


// 判断两个数的二进制位数不相同的个数
//int NumberOf1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int ret = m ^ n;
//	int count = NumberOf1(ret);
//	printf("%d\n", count);
//
//	return 0;
//}

// 求最小公倍数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b) {
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	for (i = 1; i <= a; i++)
//	{
//		if (i * b % a == 0)
//		{
//			printf("%d\n", i * b);
//			break;
//		}
//	}
//	return 0;
//}

/* ********************************** */
// 字符串逆序
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	// 输入字符串
//	gets(arr);
//	int len = strlen(arr);
//	reverse(arr, arr + len - 1);
//
//	// 每个单词逆序
//	char* start = arr;
//	while (*start)
//	{
//		char* end = start;
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		reverse(start, end - 1);
//		if (*end == ' ')
//			start = end + 1;
//		else
//			start = end;
//	}
//
//	printf("%s\n", arr);
//
//	return 0;
//}


//int f(int a, int b)
//{
//	int c = 0;
//	if (a > b)
//	{
//		c = 1;
//	}
//	else if (a == b)
//	{
//		c = 0;
//	}
//	else
//	{
//		c = -1;
//	}
//	return c;
//}
//int main()
//{
//	int i = 2;
//	int p = 0;
//	p = f(i, ++i);
//	printf("%d %d", p, i);
//
//	return 0;
//}

#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*******************************\n");
	printf("**********  1. play  **********\n");
	printf("**********  0. exit  **********\n");
	printf("*******************************\n");
}

void game()
{
	int guess = 0;

	// rand() 最大值0x7fff
	// 32767
	int ret = rand() % 100 + 1;
	
	while (1)
	{
		printf("请输入你猜的数字:>");
		scanf("%d", &guess);
		if (guess > ret)
			printf("猜大了\n");
		else if (guess < ret)
			printf("猜小了\n");
		else
		{
			printf("猜对了\n");
			break;
		}

	}
}

int main()
{
	int option = 0;

	srand((unsigned)time(NULL));

	do
	{
		menu();

		printf("请输入选项:>");
		scanf("%d", &option);
		switch (option)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (option);

	return 0;
}