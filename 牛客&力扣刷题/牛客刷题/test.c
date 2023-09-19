#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//描述
//输入描述：
//每组输入包含两个正整数n和m。(1 ≤ n ≤ 10^9，1 ≤ m ≤ 10^9)
//输出描述：
//对于每组输入，输出一个正整数，为n和m的最大公约数与最小公倍数之和。
//示例1
//输入：
//10 20
//输出：
//30
//示例2
//输入：
//15 20
//输出：
//65
// 运行超时
//int main()
//{
//	unsigned long n = 0;
//	unsigned long m = 0;
//	unsigned long i = 0;
//	unsigned long max = 0;
//	unsigned long min = 0;
//	scanf("%ld %ld", &n, &m);
//	for (i = 1; i <= n; i++)
//	{
//		if ((n % i == 0) && (m % i == 0) && max < i)
//		{
//			max = i;
//		}
//	}
//	min = (n * m) / max;
//	printf("%ld", max + min);
//	return 0;
//}
//int main()
//{
//    long n, m, c;
//    scanf("%ld %ld", &n, &m);
//    long x = n * m;
//    while (m)
//    {
//        c = n % m;
//        n = m;
//        m = c;
//    }
//    printf("%ld", (x / n) + n);
//    return 0;
//}

//描述
//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，
//想把每位的数变成0或1。如果某一位是奇数，就把它变成1，
//如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
//输入描述：
//输入包含一个整数n(0 ≤ n ≤ 10^9)
//输出描述：
//输出一个整数，即小乐乐修改后得到的数字。
//示例1
//输入：
//222222
//输出：
//0
//示例2
//输入：
//123
//输出：
//101
//int i = 0;
//void mod(int n, int a[])
//{
//	if (n > 9)
//	{
//		mod(n / 10, a);
//	}
//	a[i] = n % 10;
//	i++;
//}
//int main()
//{
//	long n = 0;
//	int a[1000] = { 0 };
//	scanf("%ld", &n);
//	mod(n, a);
//	int j = 0;
//	int k = 0;
//	for (j = 0; j < i; j++)
//	{
//		if (a[j] % 2 == 0)
//		{
//
//			a[j] = 0;
//		}
//		else
//		{
//			a[j] = 1;
//		}
//	}
//	for (j = 0; j < i; j++)
//	{
//		if (a[j] != 0)
//		{
//			printf("%d", a[j]);
//		}
//		else
//			continue;
//	}
//	return 0;
//}

//int main() {
//    int i = 0, len;
//    char s[20], d[20];
//    while ((s[i] = getchar()) != '\n')
//        i++;
//    len = i;
//    for (i = 0; i < len; i++) {
//        if ((s[i] - '0') % 2 == 0)
//            d[i] = '0';
//        if ((s[i] - '0') % 2 == 1)
//            d[i] = '1';
//    }
//    for (i = 0; i < len; i++) {
//        if (d[i] != '0') {
//            for (int j = i; j < len; j++) {
//                printf("%c", d[j]);
//            }
//            return 0;
//        }
//        else
//            continue;
//    }
//    printf("0");
//}

//描述
//KiKi这学期努力学习程序设计基础，要期末考试了，BoBo老师告诉他，总成绩包括四个部分，如下：
//总成绩 = 实验成绩 * 20 % +课堂表现成绩 * 10 % +过程考核成绩 * 20 % +期末上机考试成绩 * 50 % ，
//现在输入KiKi的各项成绩，请计算KiKi的总成绩。
//输入描述：
//一行，包括四个整数（百分制），用空格分隔，分别表示实验成绩，课堂表现成绩，过程考核成绩，期末上机考试成绩。
//输出描述：
//一行，总成绩，保留小数点一位。
//示例1
//输入：
//100 100 90 80
//输出：
//88.0
//int main()
//{
//	int a[4] = { 0 };
//	int i = 0;
//	float sum = 0;
//	for (i = 0; i < 4; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//
//	sum = a[0] * 0.2 + a[1] * 0.1 + a[2] * 0.2 + a[3] * 0.5;
//	printf("%.1f", sum);
//
//	return 0;
//}

//输入描述：
//输入为一行，用空格分隔的四个整数a、b、c、d（0 < a, b, c, d < 100, 000）。
//	输出描述：
//	输出为一行，为“(a + b - c) * d”的计算结果。
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//
//	printf("%d\n", (a + b - c) * d);
//	return 0;
//}


//#include <math.h>
//int main()
//{
//	int x1 = 0;
//	int y1 = 0;
//	int x2 = 0;
//	int y2 = 0;
//	int sum = 0;
//	scanf("%d %d", &x1, &y1);
//	scanf("%d %d", &x2, &y2);
//	sum = pow((x1 - x2), 2) + pow((y1 - y2), 2);
//	printf("%d\n", sum);
//	return 0;
//}


//int main()
//{
//	int x = 0;
//	int l = 0;
//	int r = 0;
//
//	scanf("%d %d %d", &x, &l, &r);
//
//	if (l <= x && x <= r)
//	{
//		printf("true\n");
//	}
//	else
//	{
//		printf("false\n");
//	}
//
//	return 0;
//}



//int two(int n)
//{
//    int a = 2;
//    if (n % 2 == 0)
//    {
//        printf("%d ", a);
//        return a;
//    }
//    else
//    {
//        return 0;
//    }
//}
//int three(int n)
//{
//    int a = 3;
//    if (n % 3 == 0)
//    {
//        printf("%d ", a);
//        return a;
//    }
//    else
//    {
//        return 0;
//    }
//
//}
//int seven(int n)
//{
//    int a = 7;
//    if (n % 7 == 0)
//    {
//        printf("%d ", a);
//        return a;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int t = two(n);
//    int e = three(n);
//    int s = seven(n);
//    if (t == 0 && e == 0 && s == 0)
//    {
//        printf("n\n");
//    }
//
//    return 0;
//}



//int main()
//{
//    int a[10] = { 0 };
//    int i = 0;
//    int p = 0;
//    int n = 0;
//    for (i = 0; i < 10; i++)
//    {
//        scanf("%d", &a[i]);
//        if (a[i] > 0)
//        {
//            p++;
//        }
//        else
//        {
//            n++;
//        }
//    }
//    printf("positive:%d\nnegative:%d", p, n);
//
//    return 0;
//}



//int main()
//{
//    float a = 0;
//    char b = 0;
//    scanf("%f %c", &a, &b);
//    if (a <= 1)
//    {
//        if (b == 'y')
//        {
//            printf("25\n");
//        }
//        else
//        {
//            printf("20\n");
//        }
//    }
//    else
//    {
//        int c = a;
//        if (b == 'y')
//        {
//            printf("%d\n", 25 + c);
//        }
//        else
//        {
//            printf("%d\n", 20 + c);
//        }
//    }
//
//    return 0;
//}


// 删除链表指定元素val
// 方法一
// struct ListNode {
//	 int val;
//	 struct ListNode* next;
//};
//struct ListNode* removeElements(struct ListNode* head, int val) {
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			// 头删
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

// 方法二
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* removeElements(struct ListNode* head, int val) {
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//
//	// 哨兵位的头节点
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//			del = NULL;
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				head = tail = cur;
//			}
//			else
//			{
//				tail->next = cur;
//				tail = tail->next;
//			}
//			cur = cur->next;
//		}
//
//	}
//
//	tail->next = NULL;
//
//	struct ListNode* del = head;
//	head = head->next;
//	free(del);
//
//	return head;
//}

//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	n1->val = 7;
//	n2->val = 2;
//	n3->val = 7;
//	n4->val = 7;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//
//	ListPrint(n1);
//
//	struct ListNode* ret =  removeElements(n1, 7);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 逆置链表
// 方法一
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* reverseList(struct ListNode* head) 
//{
//	struct ListNode* newhead = NULL;
//	struct ListNode* cur = head;
//
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		// 头插
//		cur->next = newhead;
//		newhead = cur;
//
//		cur = next;
//	}
//
//	return newhead;
//}

// 方法二
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
// 定义n1,n2,n3,对链表进行逆指向
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//		return NULL;
//
//	struct ListNode* n1, * n2, * n3;
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//	while (n2)
//	{
//		// 倒指向
//		n2->next = n1;
//		// 逆置
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//			n3 = n3->next;
//	}
//
//	return n1;
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//
//	ListPrint(n1);
//
//	struct ListNode* ret = reverseList(n1);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 链表的中间结点
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* fast, * slow;
//	fast = slow = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	return slow;
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//
//	ListPrint(n1);
//
//	struct ListNode* ret = middleNode(n1);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 输出该链表中倒数第k个结点
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
// 版本一
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) 
//{
//	// 传入空指针 返回空指针
//	if (pListHead == NULL)
//		return NULL;
//
//	struct ListNode* slow, * fast, * num;
//	int count = 0;
//	slow = fast = num = pListHead;
//	// 计算链表长度
//	while (num)
//	{
//		count++;
//		num = num->next;
//	}
//	//printf("count = %d\n", count);
//	// 查找的k大于count 返回空指针
//	if (k > count)
//		return NULL;
//
//	while (k--)
//	{
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	
//	return slow;
//}
// 版本二
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	struct ListNode* slow, * fast;
//	int count = 0;
//	slow = fast = pListHead;
//
//	while (k--)
//	{
//		if (fast == NULL)
//			return NULL;
//
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//
//	return slow;
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n6);
//
//	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n7);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//	n6->val = 6;
//	n7->val = 7;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = n7;
//	n7->next = NULL;
//
//	ListPrint(n1);
//
//	struct ListNode* ret = FindKthToTail(n1, 8);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 将两个有序链表合并为一个新的有序链表并返回
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};

// 不带哨兵位
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//
//    if (list2 == NULL)
//        return list1;
//
//    struct ListNode* head, * tail;
//    head = tail = NULL;
//
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            if (tail == NULL)
//            {
//                tail = head = list1;
//				list1 = list1->next;
//            }
//			else
//            {
//				tail->next = list1;
//				tail = tail->next;
//				list1 = list1->next;
//			}
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                tail = head = list2;
//				list2 = list2->next;
//            }
//			else
//            {
//                tail->next = list2;
//                tail = tail->next;
//				list2 = list2->next;
//            }
//        }
//    }
//
//    if (list1 == NULL)
//    {
//        tail->next = list2;
//    }
//    if (list2 == NULL)
//    {
//        tail->next = list1;
//    }
//
//    return head;
//}


// 带哨兵位
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* head, * tail;
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//
//
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//			tail->next = list1;
//			tail = tail->next;
//
//			list1 = list1->next;
//
//        }
//        else
//        {
//            tail->next = list2;
//            tail = tail->next;
//
//			list2 = list2->next;
//
//        }
//    }
//
//    if (list1 == NULL)
//    {
//        tail->next = list2;
//    }
//    if (list2 == NULL)
//    {
//        tail->next = list1;
//    }
//
//	// head为哨兵位的头节点
//	struct ListNode* list = head->next;
//	free(head);
//    return list;
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n6);
//
//	//struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//assert(n7);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 4;
//	n4->val = 1;
//	n5->val = 3;
//	n6->val = 4;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = NULL;
//
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = NULL;
//
//	ListPrint(n1);
//	ListPrint(n4);
//
//	struct ListNode* ret = mergeTwoLists(n1, n4);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 现有一链表的头指针 ListNode* pHead，给一定值x，
// 编写一段代码将所有小于x的结点排在其余结点之前，
// 且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//struct ListNode {
//    int val;
//    struct ListNode* next;
//    //ListNode(int x) : val(x), next(NULL) {}
//};
//
//struct ListNode* partition(struct ListNode* pHead, int x) {
//    // write code here
//	struct ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
//	lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//	greatertail->next = NULL;
//	lesstail->next = NULL;
//
//	struct ListNode* cur = pHead;
//
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			lesstail->next = cur;
//			lesstail = lesstail->next;
//		}
//		else
//		{
//			greatertail->next = cur;
//			greatertail = greatertail->next;
//		}
//		cur = cur->next;
//	}
//
//	lesstail->next = greaterhead->next;
//	greatertail->next = NULL;
//	struct ListNode* head = lesshead->next;
//	free(lesshead);
//	free(greaterhead);
//
//	return head;
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n6);
//
//	//struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//assert(n7);
//
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 5;
//	n4->val = 8;
//	n5->val = 3;
//	n6->val = 4;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = NULL;
//	//n7->next = NULL;
//
//	ListPrint(n1);
//	//ListPrint(n4);
//
//	struct ListNode* ret = partition(n1, 5);
//
//	ListPrint(ret);
//
//	return 0;
//}


// 约瑟夫问题 - 循环链表
//typedef struct node
//{
//    int data;
//    struct node* next;
//} CLinkList;
//
//int main()
//{
//    int n, m;
//    scanf("%d%d", &n, &m);//输入：骑士人数n和报到就出列的数字m
//    CLinkList* R = (CLinkList*)malloc(sizeof(CLinkList)), * p, * s;
//    p = R;
//    for (int i = 1; i <= n; i++)
//    {
//        s = (CLinkList*)malloc(sizeof(CLinkList));
//        s->data = i;
//        s->next = NULL;
//        p->next = s;
//        p = p->next;
//    }
//    p->next = R->next;
//    R = p;
//    //构造一个循环链表，使其各结点值等于i(i=1,2,3,…,n)，此时p指向最后一个结点n
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 1; j < m; j++)
//        {
//            p = p->next;
//        }
//        //令p沿循环链表前进m-1个结点
//        s = p->next;
//        p->next = s->next;
//        free(s);
//        //删除结点p的下一个结点
//    }
//    printf("最后留在圆桌旁骑士的编号为%d", p->data);//输出
//    return 0;//算法结束
//}


// 给你两个单链表的头节点 headA 和 headB
// 请你找出并返回两个单链表相交的起始节点
// 如果两个链表不存在相交节点，返回 null
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//
//    struct ListNode* lista = headA;
//    struct ListNode* listb = headB;
//	// 统计两个链表结点个数
//    int counta = 1;
//    int countb = 1;
//    while (lista->next)
//    {
//        counta++;
//        lista = lista->next;
//    }
//    while (listb->next)
//    {
//        countb++;
//        listb = listb->next;
//    }
//	// 如果两个链表地址不相同则不相交返回空
//    if (lista != listb)
//        return NULL;
//
//	// 定义长短链表
//    struct ListNode* shortlist = headA, * longlist = headB;
//	// 若与定义情况不符合
//	// 重新储存链表
//    if (counta > countb)
//    {
//        shortlist = headB;
//        longlist = headA;
//    }
//	// 计算两个链表相差的节点数
//    int gap = abs(counta - countb);
//	// 长链表先走gap步
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//	// 长链表剩下的结点与短链表所有节点比较,找到相交结点终止循环
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//	// 返回任意链表
//    return shortlist;
//    //return longlist;
//
//}
//
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	if (head == NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		while (cur)
//		{
//			printf("%d->", cur->val);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1);
//
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n2);
//
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n3);
//
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n4);
//
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n5);
//
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n6);
//
//	//struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//assert(n7);
//
//	n1->val = 4;
//
//	n2->val = 2;
//	n3->val = 2;
//	n4->val = 4;
//	n5->val = 5;
//	n6->val = 4;
//
//
//	n1->next = NULL;
//
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = NULL;
//	//n7->next = NULL;
//
//	ListPrint(n1);
//	//ListPrint(n4);
//
//	struct ListNode* ret = getIntersectionNode(n1, n2);
//
//	ListPrint(ret);
//
//	return 0;
//}



// 给定一个链表的头节点  head ，
// 返回链表开始入环的第一个节点。 
// 如果链表无环，则返回 null。
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    struct ListNode* newhead = head;
//
//    while (fast && fast->next)
//    {
//        // 追逐
//        slow = slow->next;
//        fast = fast->next->next;
//        // fast追上slow时
//        if (slow == fast)
//        {
//            // 定义新的结构体指针,将快慢指针相遇的结点赋过去
//            struct ListNode* meet = slow;
//            // 头结点和快慢指针相遇的结点相同就是入环结点
//            while (newhead != meet)
//            {
//                newhead = newhead->next;
//                meet = meet->next;
//            }
//            return meet;
//        }
//    }
//    return NULL;
//}


// 给你一个长度为 n 的链表，
// 每个节点包含一个额外增加的随机指针 random ，
// 该指针可以指向链表中的任何节点或空节点。
//
// 构造这个链表的 深拷贝。 
// 深拷贝应该正好由 n 个 全新 节点组成，
// 其中每个新节点的值都设为其对应的原节点的值。
// 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
// 并使原链表和复制链表中的这些指针能够表示相同的链表状态。
// 复制链表中的指针都不应指向原链表中的节点 。
//
//struct Node {
//	int val;
//	struct Node* next;
//	struct Node* random;
//};
//
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    // 1. copy结点链接在源结点的后面
//    while (cur)
//    {
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        copy->next = cur->next;
//        cur->next = copy;
//        cur = copy->next;
//    }
//    // 2. 将原链表的random复制到copy链表中
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = copy->next;
//    }
//    // 3. 将copy链表截下来,链接到一起,恢复原来的链表
//    cur = head;
//    struct Node* copyHead = NULL;
//    struct Node* copyTail = NULL;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//        if (copyHead == NULL)
//        {
//            copyHead = copyTail = copy;
//        }
//        else
//        {
//            copyTail->next = copy;
//            copyTail = copyTail->next;
//        }
//        cur->next = next;
//        cur = next;
//    }
//    return copyHead;
//}



//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
typedef int QDataType;

typedef struct QueueNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;

}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		Queue* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->tail == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&obj->q1);
	QueueInit(&obj->q2);

	return obj;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}

	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}

	int top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);

	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);

	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/