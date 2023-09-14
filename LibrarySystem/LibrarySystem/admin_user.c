#define _CRT_SECURE_NO_WARNINGS 1

#include "function.h"

// ͼ�����Ա����
typedef struct Library
{
	char type[MAXSIZE];                // ͼ�����
	char ID[MAXSIZE];                  // ���
	char name[MAXSIZE];                // ����
	char aborrow[MAXSIZE];             // �ѽ������
	char iborrow[MAXSIZE];             // δ�������
} Library;

Library lib_arr[MAXSIZE] = {
	{"�ƻ�", "1001001", "δ��ս��", "5", "1"},
	{"�ƻ�", "1001002", "δ��ս��2", "1", "6"},
	{"�̿�", "1002102", "���Ľ�ѧ", "0", "10"},
	{"�ƻ�", "1002309", "���ڻ���", "5", "2"}
};

void AdminMenu() {
	printf("=============ͼ��ά��ϵͳ============\n");
	printf("1. ����ͼ��\n");
	printf("2. ����ͼ����Ϣ\n");
	printf("3. ɾ��ͼ��\n");
	printf("4. ����ͼ��\n");
	printf("5. ��ʾ����ͼ����Ϣ\n");
	printf("6. ȫɾ��ǰ����\n");
	printf("0. �˳�\n");
	printf("================��ѡ��===============\n");
}

// 1. ����ͼ��
void AddBook(Library lib_arr[], int* length) {
	//����洢����Ϣ���Ѵ����
	if (*length == MAXSIZE) {
		printf("������Ӹ����ѧ����Ϣ�ˣ�\n");
		return;
	}
	printf("ͼ����� ��� ���� �ѽ�������� δ���������\n");

	Library lib;
	scanf("%s %s %s %s %s", &lib.type, &lib.ID, &lib.name, &lib.aborrow, &lib.iborrow);

	lib_arr[*length] = lib;
	(*length)++;
	int tem = (*length) - 1;
	printf("ͼ�� %s ��Ϣ��ӳɹ���\n", lib_arr[tem].name);
	system("pause");
	system("cls");
	Sleep(1000);
}

// 2. ����ͼ����Ϣ
void UpdateBook(Library lib_arr[], int length) {
	char ID[MAXSIZE];
	printf("������Ҫ�޸ĵ���ţ�");
	scanf("%s", &ID);

	int i = 0;
	int is_find = 0;
	for (i = 0; i < length && is_find == 0; i++) {
		if (strcmp(lib_arr[i].ID, ID) == 0) {
			is_find = 1;
			printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
				lib_arr[i].type, lib_arr[i].ID,
				lib_arr[i].name, lib_arr[i].aborrow,
				lib_arr[i].iborrow);
			printf("==========������ĺ����Ϣ==========\n");
			printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
			scanf("%s %s %s %s %s",
				&lib_arr[i].type, &lib_arr[i].ID,
				&lib_arr[i].name, &lib_arr[i].aborrow,
				&lib_arr[i].iborrow);
		}
	}

	if (is_find == 0) {
		printf("δ�ҵ���ѧ����Ϣ��\n");
	}
	else {
		printf("�鱾 %s �޸ĳɹ���\n", ID);
	}
	system("pause");
	system("cls");
	Sleep(1000);
}


// 3. ɾ��ͼ��
void DeleteBook(Library lib_arr[], int* length) {
	//��������Ѿ�Ϊ��
	if (length == 0) {
		printf("û�п�ɾ�������ݣ�\n");
		return;
	}

	char ID[MAXSIZE];
	printf("������Ҫɾ������ţ�");
	scanf("%s", &ID);

	int i = 0;
	int j = 0;
	int is_find = 0;
	for (i = 0; i < *length && is_find == 0; i++) {
		if (strcmp(lib_arr[i].ID, ID) == 0) {
			is_find = 1;
			//�Ա�ɾ����Ϣ���и���
			for (j = i; j < (*length) - 1; j++) {
				lib_arr[j] = lib_arr[j + 1];
			}
		}
	}

	if (is_find == 0) {
		printf("δ�ҵ�����ţ�\n");
	}
	else {
		(*length)--;
		printf("��� %s ɾ���ɹ���\n", ID);
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

// 4. ����ͼ��
void FindBook(Library lib_arr[], int length) {
	int input = 0;
	char find[MAXSIZE];
	int i = 0;
	int is_find = 0;
	printf("��ѡ����ҷ�ʽ��\n");
	printf("�˳���0,�������Ұ�1,�����Ұ�2,��Ų��Ұ�3��");
	scanf("%d", &input);

	if (input == 1) {
		printf("������Ҫ���ҵ�������");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].name, find) == 0) {
				is_find = 1;
				printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	else if (input == 2) {
		printf("������Ҫ���ҵ�������");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].type, find) == 0) {
				is_find = 1;
				printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	else {
		printf("������Ҫ���ҵ�������");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].ID, find) == 0) {
				is_find = 1;
				printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	if (is_find == 0) {
		printf("���޴���!\n");
	}
	system("pause");
	system("cls");
	Sleep(1000);
}


// 5. ��ʾ����ͼ����Ϣ
void PrintAll(Library lib_arr[], int length) {
	printf("���\t\t���\t\t����\t\t�ѽ��������\t\tδ���������\n");
	int i;
	for (i = 0; i < length; i++) {
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
			lib_arr[i].type, lib_arr[i].ID,
			lib_arr[i].name, lib_arr[i].aborrow,
			lib_arr[i].iborrow);
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

// 6. ȫɾ��ǰ����
void DeletAll(Library lib_arr[], int* length) {
	Library delet[MAXSIZE] = { 0 };
	int i = 0;
	int j = 0;
	if (length == 0) {
		printf("û�п�ɾ�������ݣ�\n");
		return;
	}

	for (j = i; j <= (*length) - 1; j++) {
		lib_arr[j] = delet[j + 1];
	}

	printf("================�Ѿ�ȫɾ=================\n");
	system("pause");
	system("cls");
	Sleep(1000);
}

void admin() {
	int input = 0;
	int len = strlen(lib_arr);
	int i = 0;

	FILE* book = fopen("ͼ����Ϣ.txt", "w");
	//�ж��ļ��Ƿ�ɹ���
	if (book == NULL) {
		printf("File open failed!\n");
		Sleep(1000);
		system("pause");
		system("cls");
	}
	else {
		for (i = 0; i < len; i++) {
			fprintf(book, "%s %s %s %s %s\n",
				lib_arr[i].type, lib_arr[i].ID,
				lib_arr[i].name, lib_arr[i].aborrow,
				lib_arr[i].iborrow);
		}
	}
	fclose(book);

	do
	{
		AdminMenu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddBook(lib_arr, &len);
			break;
		case 2:
			UpdateBook(lib_arr, len);
			break;
		case 3:
			DeleteBook(lib_arr, &len);
			break;
		case 4:
			FindBook(lib_arr, len);
			break;
		case 5:
			PrintAll(lib_arr, len);
			break;
		case 6:
			DeletAll(lib_arr, &len);
			break;
		case 0:
			printf("�˳�����~\n");
			break;
		default:
			printf("ѡ�����!����ѡ��!\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);
}

// �����û�����
// �˴����û��˺�Ϊ 104173101
typedef struct Reader {
	char ID[MAXSIZE];                // ѧ��
	char name[MAXSIZE];              // ����
	char aborrow[MAXSIZE];           // �ѽ������
	char bookitem[MAXSIZE];          // ������Ŀ
	char maxborrow[MAXSIZE];         // ����������
} Reader;

Reader read_arr[MAXSIZE] = {
			{"104173101", "����", "3", {"1001002 1001002 1001001 "}, "5"},
			{"104173102", "����", "3", {"1001002 1002309 1002102 "}, "5"},
			{"104173103", "����", "5", {"1001001 1002309 1002309 1002309 1002309 "}, "5"}
};

void UserMenu() {
	printf("=============ͼ��ά��ϵͳ============\n");
	printf("1. ����ͼ��\n");
	printf("2. �黹ͼ��\n");
	printf("3. �鿴����ͼ��\n");
	printf("4. ����ͼ��\n");
	printf("5. ��ʾ�ҵ���Ϣ\n");
	printf("0. �˳�\n");
	printf("================��ѡ��===============\n");
}

// 1. ����ͼ��
void BorrowBook(Reader read_arr[], int length) {
	int i = 0;
	char find[MAXSIZE];
	int is_find = 0;

    in:printf("����������Ҫ���ĵ���ţ�");
	scanf("%s", &find);

	for (i = 0; i < length; i++) {
		// �ж�������������Ƿ����,���ж��˺���Ϣ
		if ((strcmp(lib_arr[i].ID, find) == 0) && (is_find == 0)) {
			is_find = 1;
			// �ַ���ƴ�Ӻ���
			// read_arr[0]������  read_arr[1]������  read_arr[2]������
			strcat(read_arr[0].bookitem, find);
			// �ַ������ƺ���
			// read_arr[0]������  read_arr[1]������  read_arr[2]������
			strcpy(read_arr[0].aborrow, "4");
			strcpy(lib_arr[i].aborrow, "6");
			strcpy(lib_arr[i].iborrow, "1");
			printf("���� %s �ɹ�\n", find);
		}
		
	}
	if (is_find == 0) {
		printf("������Ų�����!����������!\n");
		goto in;
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

// 2. �黹ͼ��
// ������ ���������Ҫ���Ĵ���
void ReturnBook(Reader read_arr[], int length) {
	int i = 0;
	char _return[MAXSIZE];
	int is_return = 0;
	in:printf("����������Ҫ�黹����ţ�");
	scanf("%s", &_return);

	for (i = 0; i < length; i++) {
		if (strstr(read_arr[0].bookitem, _return) != NULL && is_return == 0 && strcmp(lib_arr[i].ID, _return) == 0) {
			is_return = 1;
			strcpy(read_arr[0].bookitem, "1001002 1001002 1001001 ");
			strcpy(read_arr[0].aborrow, "3");
			strcpy(lib_arr[i].aborrow, "5");
			strcpy(lib_arr[i].iborrow, "2");
		}
	}

	if(is_return == 0) {
		printf("����������!��δ�����!\n");
		system("pause");
		goto in;
	}
	
	/*for (i = 0; i < length; i++) {
		if (strcmp((strstr(read_arr[0].ID, ret)), ret) == 0 && is_return == 0) {
			is_return = 1;
			delchar(read_arr[0].ID, ret);
		}
		else {
			printf("�黹ʧ�ܣ�������������ţ�\n");
		}
	}*/
	printf("�黹�ɹ�!\n");
	system("pause");
	system("cls");
	Sleep(1000);
}

// 3. �鿴����ͼ��
// admin.c�еĺ���
// PrintAll(lib_arr, len);
// 4. ����ͼ��
// admin.c�еĺ���
// FindBook(lib_arr, len);
// 5. ��ʾ�ҵ���Ϣ
void ShowMe(Reader read_arr[], int length) {
	int i = 0;
	printf("ѧ��\t\t����\t�ѽ��������\t����������\t������Ŀ\n");
	for (i = 0; i < length; i++) {
		// �Ƚϵ�½�˺���ṹ�������е�ѧ��
		// �ַ���"104173102"���������,ֻ���ڽṹ������������
		if (strcmp(read_arr[i].ID, "104173101") == 0) {
			printf("%s\t%s\t%s\t\t%s\t\t%s\n",
				read_arr[i].ID, read_arr[i].name,
				read_arr[i].aborrow, read_arr[i].maxborrow,
				read_arr[i].bookitem);
		}
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

void user() {
	char id[MAXSIZE] = { 0 };
	in:printf("�û�����ѧ�ŵ�¼��");
	scanf("%s", &id);

	// ȷ�ϵ�¼�˺�Ϊ104173101
	if (strcmp(id, "104173101") == 0) {
		printf("��¼�ɹ�!\n");
		system("pause");
		system("cls");
		int input = 0;

		int length = strlen(read_arr);
		int len = strlen(lib_arr);
		int i = 0;
		// ��ֻд��ʽ�򿪶�����Ϣ.txt
		FILE* read = fopen("������Ϣ.txt", "w");
		// �ж��ļ��Ƿ�ɹ���
		if (read == NULL) {
			printf("File open failed!\n");
			Sleep(1000);
			system("pause");
			system("cls");
		}
		else {
			for (i = 0; i < length; i++) {
				fprintf(read, "%s %s %s %s %s\n",
					read_arr[i].ID, read_arr[i].name,
					read_arr[i].aborrow, read_arr[i].bookitem,
					read_arr[i].maxborrow);
			}
		}
		fclose(read);

		do {
			UserMenu();
			printf("��ѡ��:> ");
			scanf("%d", &input);
			switch (input) {
			case 1:
				BorrowBook(read_arr, length);
				break;
			case 2:
				ReturnBook(read_arr, length);
				break;
			case 3:
				PrintAll(lib_arr, len);
				break;
			case 4:
				FindBook(lib_arr, len);
				break;
			case 5:
				ShowMe(read_arr, length);
				break;
			case 0:
				printf("�˳�����~\n");
				break;
			default:
				printf("ѡ�����!����ѡ��!\n");
				break;
			}
		} while (input);
	}
	else {
		printf("ѧ���������!����������!\n");
		goto in;
	}
}