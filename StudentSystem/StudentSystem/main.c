#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define N 100         // 定义学号、姓名数组的长度
#define LEN 5         // 定义结构体数组的长度

typedef struct Student {
	char ID[N];       // 学号
	char name[N];     // 姓名
	float chinese;    // 语文成绩
	float math;       // 数学成绩
	float english;    // 英语成绩
	float ave;        // 平均分
} Student;

void menu()
{
	printf("==========================\n");
	printf("1.查看全部学生信息\n");
	printf("2.查看挂科学生信息\n");
	printf("3.按学号排序\n");
	printf("4.按平均分排序\n");
	printf("5.计算各科平均分\n");
	printf("6.保存当前数据\n");
	printf("0.退出\n");
	printf("==========================\n");
}

// 平均分排序函数
int CmpByAve(const void* x, const void* y) {
	Student stu_x = *(Student*)x;
	Student stu_y = *(Student*)y;

	return stu_x.ave < stu_y.ave;
}

// 学号排序函数
int CmpByID(const void* x, const void* y) {
	Student stu_x = *(Student*)x;
	Student stu_y = *(Student*)y;

	return strcmp(stu_x.ID, stu_y.ID);
}

//1. 显示所有学生信息
void PrintAll(Student stu_arr[], int length) {
	printf("学号\t\t姓名\t语文\t数学\t英语\t平均分\n");
	int i;
	for (i = 0; i < length; i++) {
		printf("%s\t%s\t%.0f\t%.0f\t%.0f\t%.2f\n",
			stu_arr[i].ID, stu_arr[i].name,
			stu_arr[i].chinese, stu_arr[i].math,
			stu_arr[i].english, stu_arr[i].ave);
	}
	Sleep(1000);
	system("pause");
	system("cls");
}

//2. 查看不及格的学生
void ShowFailStudent(Student stu_arr[], int length) {
	printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
	int i;
	for (i = 0; i < length; i++) {
		int sum = 0;
		// 平均分小于60
		if (stu_arr[i].ave < 60) sum++;
		// 打印不及格
		if (sum) {
			printf("%s\t%s\t%.0f\t%.0f\t%.0f\t%.2f\n",
				stu_arr[i].ID, stu_arr[i].name,
				stu_arr[i].chinese, stu_arr[i].math,
				stu_arr[i].english, stu_arr[i].ave);
		}
	}
	Sleep(1000);
	system("pause");
	system("cls");
}

//3.按学号排序
void ShowIDKing(Student stu_arr[], int length) {
	qsort(stu_arr, length, sizeof(Student), CmpByID);
	//printf("排序成功！\n");
	PrintAll(stu_arr, length);

	Sleep(1000);
	system("pause");
	system("cls");
}


//4.按平均分排序
void ShowAveKing(Student stu_arr[], int length) {
	qsort(stu_arr, length, sizeof(Student), CmpByAve);
	//printf("排序成功！\n");
	PrintAll(stu_arr, length);

	Sleep(1000);
	system("pause");
	system("cls");
}

//5.计算各科平均分
void CalculateAve(Student stu_arr[], int length) {
	printf("语文\t数学\t英语\n");
	int i = 0;
	float sum_c = 0;
	float sum_m = 0;
	float sum_e = 0;
	for (i = 0; i < length; i++) {
		sum_c += stu_arr[i].chinese;
		sum_m += stu_arr[i].math;
		sum_e += stu_arr[i].english;
	}
	printf("%.2f\t%.2f\t%.2f\n", sum_c / 5, sum_m / 5, sum_e / 5);
	Sleep(1000);
	system("pause");
	system("cls");
}

//6.保存当前数据
void SaveData(Student stu_arr[], FILE* student, int length) {
	int i = 0;

	student = fopen("student.txt", "w");
	//判断文件是否成功打开
	if (student == NULL) {
		printf("File open failed!\n");
		Sleep(1000);
		system("pause");
		system("cls");
	}
	else {
		for (i = 0; i < length; i++) {
			fprintf(student, "%s\t%s\t%.0f\t%.0f\t%.0f\t%.2f\n",
				stu_arr[i].ID, stu_arr[i].name,
				stu_arr[i].chinese, stu_arr[i].math,
				stu_arr[i].english, stu_arr[i].ave);
		}
	}
	fclose(student);
}

int main()
{
	// 选项
	int input = 0;
	// 定义结构体数组内容
	Student stu_arr[] = {
		{"000000001", "马七", 0, 1, 0, 0.33},
		{"000000002", "王五", 50, 60, 60, 56.67},
		{"000000003", "李四", 90, 90, 90, 90.00},
		{"000000000", "张三", 100, 99, 98, 99.00},
		{"000000004", "赵六", 30, 50, 80, 53.33}
	};
	FILE* student = fopen("student.txt", "r");
	// 若文件不存在则终止程序
	if (student == NULL)
	{
		printf("open error!\n");
		return 0;
	}
	else
	{
		printf("文件读取完毕！");
		system("pause");
		system("cls");
	}
	// fclose(p);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			PrintAll(stu_arr, LEN);
			break;
		case 2:
			ShowFailStudent(stu_arr, LEN);
			break;
		case 3:
			ShowIDKing(stu_arr, LEN);
			break;
		case 4:
			ShowAveKing(stu_arr, LEN);
			break;
		case 5:
			CalculateAve(stu_arr, LEN);
			break;
		case 6:
			SaveData(stu_arr, student, LEN);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("选择错误!请重新选择!\n");
			break;
		}
	} while (input);

	return 0;
}
