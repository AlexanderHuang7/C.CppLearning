#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define N 100         // ����ѧ�š���������ĳ���
#define LEN 5         // ����ṹ������ĳ���

typedef struct Student {
	char ID[N];       // ѧ��
	char name[N];     // ����
	float chinese;    // ���ĳɼ�
	float math;       // ��ѧ�ɼ�
	float english;    // Ӣ��ɼ�
	float ave;        // ƽ����
} Student;

void menu()
{
	printf("==========================\n");
	printf("1.�鿴ȫ��ѧ����Ϣ\n");
	printf("2.�鿴�ҿ�ѧ����Ϣ\n");
	printf("3.��ѧ������\n");
	printf("4.��ƽ��������\n");
	printf("5.�������ƽ����\n");
	printf("6.���浱ǰ����\n");
	printf("0.�˳�\n");
	printf("==========================\n");
}

// ƽ����������
int CmpByAve(const void* x, const void* y) {
	Student stu_x = *(Student*)x;
	Student stu_y = *(Student*)y;

	return stu_x.ave < stu_y.ave;
}

// ѧ��������
int CmpByID(const void* x, const void* y) {
	Student stu_x = *(Student*)x;
	Student stu_y = *(Student*)y;

	return strcmp(stu_x.ID, stu_y.ID);
}

//1. ��ʾ����ѧ����Ϣ
void PrintAll(Student stu_arr[], int length) {
	printf("ѧ��\t\t����\t����\t��ѧ\tӢ��\tƽ����\n");
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

//2. �鿴�������ѧ��
void ShowFailStudent(Student stu_arr[], int length) {
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\tƽ����\n");
	int i;
	for (i = 0; i < length; i++) {
		int sum = 0;
		// ƽ����С��60
		if (stu_arr[i].ave < 60) sum++;
		// ��ӡ������
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

//3.��ѧ������
void ShowIDKing(Student stu_arr[], int length) {
	qsort(stu_arr, length, sizeof(Student), CmpByID);
	//printf("����ɹ���\n");
	PrintAll(stu_arr, length);

	Sleep(1000);
	system("pause");
	system("cls");
}


//4.��ƽ��������
void ShowAveKing(Student stu_arr[], int length) {
	qsort(stu_arr, length, sizeof(Student), CmpByAve);
	//printf("����ɹ���\n");
	PrintAll(stu_arr, length);

	Sleep(1000);
	system("pause");
	system("cls");
}

//5.�������ƽ����
void CalculateAve(Student stu_arr[], int length) {
	printf("����\t��ѧ\tӢ��\n");
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

//6.���浱ǰ����
void SaveData(Student stu_arr[], FILE* student, int length) {
	int i = 0;

	student = fopen("student.txt", "w");
	//�ж��ļ��Ƿ�ɹ���
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
	// ѡ��
	int input = 0;
	// ����ṹ����������
	Student stu_arr[] = {
		{"000000001", "����", 0, 1, 0, 0.33},
		{"000000002", "����", 50, 60, 60, 56.67},
		{"000000003", "����", 90, 90, 90, 90.00},
		{"000000000", "����", 100, 99, 98, 99.00},
		{"000000004", "����", 30, 50, 80, 53.33}
	};
	FILE* student = fopen("student.txt", "r");
	// ���ļ�����������ֹ����
	if (student == NULL)
	{
		printf("open error!\n");
		return 0;
	}
	else
	{
		printf("�ļ���ȡ��ϣ�");
		system("pause");
		system("cls");
	}
	// fclose(p);

	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����!������ѡ��!\n");
			break;
		}
	} while (input);

	return 0;
}
