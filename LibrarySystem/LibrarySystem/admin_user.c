#define _CRT_SECURE_NO_WARNINGS 1

#include "function.h"

// 图书管理员内容
typedef struct Library
{
	char type[MAXSIZE];                // 图书类别
	char ID[MAXSIZE];                  // 书号
	char name[MAXSIZE];                // 书名
	char aborrow[MAXSIZE];             // 已借出数量
	char iborrow[MAXSIZE];             // 未借出数量
} Library;

Library lib_arr[MAXSIZE] = {
	{"科幻", "1001001", "未来战争", "5", "1"},
	{"科幻", "1001002", "未来战争2", "1", "6"},
	{"教科", "1002102", "语文教学", "0", "10"},
	{"科幻", "1002309", "我在火星", "5", "2"}
};

void AdminMenu() {
	printf("=============图书维护系统============\n");
	printf("1. 新增图书\n");
	printf("2. 更改图书信息\n");
	printf("3. 删除图书\n");
	printf("4. 查找图书\n");
	printf("5. 显示所有图书信息\n");
	printf("6. 全删当前数据\n");
	printf("0. 退出\n");
	printf("================请选择===============\n");
}

// 1. 新增图书
void AddBook(Library lib_arr[], int* length) {
	//如果存储的信息量已达最大
	if (*length == MAXSIZE) {
		printf("不能添加更多的学生信息了！\n");
		return;
	}
	printf("图书类别 书号 书名 已借出的数量 未借出的数量\n");

	Library lib;
	scanf("%s %s %s %s %s", &lib.type, &lib.ID, &lib.name, &lib.aborrow, &lib.iborrow);

	lib_arr[*length] = lib;
	(*length)++;
	int tem = (*length) - 1;
	printf("图书 %s 信息添加成功！\n", lib_arr[tem].name);
	system("pause");
	system("cls");
	Sleep(1000);
}

// 2. 更改图书信息
void UpdateBook(Library lib_arr[], int length) {
	char ID[MAXSIZE];
	printf("请输入要修改的书号：");
	scanf("%s", &ID);

	int i = 0;
	int is_find = 0;
	for (i = 0; i < length && is_find == 0; i++) {
		if (strcmp(lib_arr[i].ID, ID) == 0) {
			is_find = 1;
			printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
				lib_arr[i].type, lib_arr[i].ID,
				lib_arr[i].name, lib_arr[i].aborrow,
				lib_arr[i].iborrow);
			printf("==========输入更改后的信息==========\n");
			printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
			scanf("%s %s %s %s %s",
				&lib_arr[i].type, &lib_arr[i].ID,
				&lib_arr[i].name, &lib_arr[i].aborrow,
				&lib_arr[i].iborrow);
		}
	}

	if (is_find == 0) {
		printf("未找到该学生信息！\n");
	}
	else {
		printf("书本 %s 修改成功！\n", ID);
	}
	system("pause");
	system("cls");
	Sleep(1000);
}


// 3. 删除图书
void DeleteBook(Library lib_arr[], int* length) {
	//如果数组已经为空
	if (length == 0) {
		printf("没有可删除的数据！\n");
		return;
	}

	char ID[MAXSIZE];
	printf("请输入要删除的书号：");
	scanf("%s", &ID);

	int i = 0;
	int j = 0;
	int is_find = 0;
	for (i = 0; i < *length && is_find == 0; i++) {
		if (strcmp(lib_arr[i].ID, ID) == 0) {
			is_find = 1;
			//对被删除信息进行覆盖
			for (j = i; j < (*length) - 1; j++) {
				lib_arr[j] = lib_arr[j + 1];
			}
		}
	}

	if (is_find == 0) {
		printf("未找到该书号！\n");
	}
	else {
		(*length)--;
		printf("书号 %s 删除成功！\n", ID);
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

// 4. 查找图书
void FindBook(Library lib_arr[], int length) {
	int input = 0;
	char find[MAXSIZE];
	int i = 0;
	int is_find = 0;
	printf("请选择查找方式：\n");
	printf("退出按0,书名查找按1,类别查找按2,书号查找按3：");
	scanf("%d", &input);

	if (input == 1) {
		printf("请输入要查找的书名：");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].name, find) == 0) {
				is_find = 1;
				printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	else if (input == 2) {
		printf("请输入要查找的书名：");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].type, find) == 0) {
				is_find = 1;
				printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	else {
		printf("请输入要查找的书名：");
		scanf("%s", &find);
		for (i = 0; i < length && is_find == 0; i++) {
			if (strcmp(lib_arr[i].ID, find) == 0) {
				is_find = 1;
				printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
				printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
					lib_arr[i].type, lib_arr[i].ID,
					lib_arr[i].name, lib_arr[i].aborrow,
					lib_arr[i].iborrow);
			}
		}
	}
	if (is_find == 0) {
		printf("查无此类!\n");
	}
	system("pause");
	system("cls");
	Sleep(1000);
}


// 5. 显示所有图书信息
void PrintAll(Library lib_arr[], int length) {
	printf("类别\t\t书号\t\t书名\t\t已借出的数量\t\t未借出的数量\n");
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

// 6. 全删当前数据
void DeletAll(Library lib_arr[], int* length) {
	Library delet[MAXSIZE] = { 0 };
	int i = 0;
	int j = 0;
	if (length == 0) {
		printf("没有可删除的数据！\n");
		return;
	}

	for (j = i; j <= (*length) - 1; j++) {
		lib_arr[j] = delet[j + 1];
	}

	printf("================已经全删=================\n");
	system("pause");
	system("cls");
	Sleep(1000);
}

void admin() {
	int input = 0;
	int len = strlen(lib_arr);
	int i = 0;

	FILE* book = fopen("图书信息.txt", "w");
	//判断文件是否成功打开
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
		printf("请选择:> ");
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
			printf("退出程序~\n");
			break;
		default:
			printf("选择错误!重新选择!\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);
}

// 借书用户内容
// 此代码用户账号为 104173101
typedef struct Reader {
	char ID[MAXSIZE];                // 学号
	char name[MAXSIZE];              // 姓名
	char aborrow[MAXSIZE];           // 已借出数量
	char bookitem[MAXSIZE];          // 借书项目
	char maxborrow[MAXSIZE];         // 最大借书数量
} Reader;

Reader read_arr[MAXSIZE] = {
			{"104173101", "张三", "3", {"1001002 1001002 1001001 "}, "5"},
			{"104173102", "李三", "3", {"1001002 1002309 1002102 "}, "5"},
			{"104173103", "王五", "5", {"1001001 1002309 1002309 1002309 1002309 "}, "5"}
};

void UserMenu() {
	printf("=============图书维护系统============\n");
	printf("1. 借阅图书\n");
	printf("2. 归还图书\n");
	printf("3. 查看所有图书\n");
	printf("4. 查找图书\n");
	printf("5. 显示我的信息\n");
	printf("0. 退出\n");
	printf("================请选择===============\n");
}

// 1. 借阅图书
void BorrowBook(Reader read_arr[], int length) {
	int i = 0;
	char find[MAXSIZE];
	int is_find = 0;

    in:printf("请输入你想要借阅的书号：");
	scanf("%s", &find);

	for (i = 0; i < length; i++) {
		// 判断所搜索的书号是否存在,且判断账号信息
		if ((strcmp(lib_arr[i].ID, find) == 0) && (is_find == 0)) {
			is_find = 1;
			// 字符串拼接函数
			// read_arr[0]：张三  read_arr[1]：李三  read_arr[2]：王五
			strcat(read_arr[0].bookitem, find);
			// 字符串复制函数
			// read_arr[0]：张三  read_arr[1]：李三  read_arr[2]：王五
			strcpy(read_arr[0].aborrow, "4");
			strcpy(lib_arr[i].aborrow, "6");
			strcpy(lib_arr[i].iborrow, "1");
			printf("借阅 %s 成功\n", find);
		}
		
	}
	if (is_find == 0) {
		printf("搜索书号不存在!请重新输入!\n");
		goto in;
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

// 2. 归还图书
// 死代码 更改情况需要更改代码
void ReturnBook(Reader read_arr[], int length) {
	int i = 0;
	char _return[MAXSIZE];
	int is_return = 0;
	in:printf("请输入你想要归还的书号：");
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
		printf("书号输入错误!或未借此书!\n");
		system("pause");
		goto in;
	}
	
	/*for (i = 0; i < length; i++) {
		if (strcmp((strstr(read_arr[0].ID, ret)), ret) == 0 && is_return == 0) {
			is_return = 1;
			delchar(read_arr[0].ID, ret);
		}
		else {
			printf("归还失败！请重新输入书号！\n");
		}
	}*/
	printf("归还成功!\n");
	system("pause");
	system("cls");
	Sleep(1000);
}

// 3. 查看所有图书
// admin.c中的函数
// PrintAll(lib_arr, len);
// 4. 查找图书
// admin.c中的函数
// FindBook(lib_arr, len);
// 5. 显示我的信息
void ShowMe(Reader read_arr[], int length) {
	int i = 0;
	printf("学号\t\t姓名\t已借出的数量\t最大借书数量\t借书项目\n");
	for (i = 0; i < length; i++) {
		// 比较登陆账号与结构体数组中的学号
		// 字符串"104173102"可任意更改,只需在结构体中声明即可
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
	in:printf("用户输入学号登录：");
	scanf("%s", &id);

	// 确认登录账号为104173101
	if (strcmp(id, "104173101") == 0) {
		printf("登录成功!\n");
		system("pause");
		system("cls");
		int input = 0;

		int length = strlen(read_arr);
		int len = strlen(lib_arr);
		int i = 0;
		// 以只写方式打开读者信息.txt
		FILE* read = fopen("读者信息.txt", "w");
		// 判断文件是否成功打开
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
			printf("请选择:> ");
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
				printf("退出程序~\n");
				break;
			default:
				printf("选择错误!重新选择!\n");
				break;
			}
		} while (input);
	}
	else {
		printf("学号输入错误!请重新输入!\n");
		goto in;
	}
}