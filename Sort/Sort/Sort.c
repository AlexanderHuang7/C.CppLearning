#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "stack.h"

void Swap(int* p1, int* p2)
{
	assert(p1 && p2);

	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// ��������
void InsertSort(int* a, int n)
{
	assert(a);

	//int i = 0;
	//for (i = 0; i < n - 1; i++)
	//{
	//	int end = i + 1;
	//	if (a[end] < a[i])
	//	{
	//		int k = i;
	//		int temp = a[end];
	//		while (temp < a[k] && k >= 0)
	//		{
	//			a[k + 1] = a[k];
	//			k--;
	//			end--;
	//		}
	//		a[end] = temp;
	//	}
	//}

	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}

}

// ϣ������
void ShellSort(int* a, int n)
{
	assert(a);

	//int gap = 3;
	//for (int j = 0; j < gap; ++j)
	//{
	//	for (int i = j; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int temp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (temp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = temp;
	//	}
	//}

	//SortPrint(a, n);
	// gap > 1��Ԥ����
	// gap���һ�ε���1,��ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
		//printf("gap=%d->", gap);
		//SortPrint(a, n);
	}
}

// ѡ������
// O(N^2)
// �����������
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[mini], &a[begin]);

		if (maxi == begin)
		{
			maxi = mini;
		}

		Swap(&a[maxi], &a[end]);
		end--;
		begin++;
	}
}

// ������
// ���򽨴��
// ����С��
void AdjustDwon(int* a, int size, int parent)
{
	assert(a);

	int child = parent * 2 + 1;

	while (child < size)
	{
#if 0
		// С��
		if (child + 1 < size && (a[child + 1] < a[child]))
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
#elif 1
		// ���
		if (child + 1 < size && (a[child + 1] > a[child]))
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
#endif
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	assert(a);

	int i = 0;
	// ����
#if 0
	// O(N*logN)
	for (i = 1; i < n; ++i)
	{
		AdjustUp(a, i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
#elif 1
	// O(N)
	for (i = (n-1-1)/2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	//for (i = 0; i < n; i++)
	//{
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
#endif
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
	//for (i = 0; i < n; i++)
	//{
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
}

// ð������
// O(N^2) ������O(N)
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int j = 0; j < n; ++j)
	{
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] < a[i])
			{
				Swap(&a[i], &a[i - 1]);
			}
		}
	}
}

// ����ȡ�з�
int GetMinIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	// a[begin] > a[mid]
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

// ��������ݹ�ʵ��
// ��������hoare�汾
int QuickSortHoare(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		// �ұ�����,��С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// ��ߺ���,�Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// ���������ڿӷ�
int QuickSortPotholing(int* a, int begin, int end)
{
	int key = a[begin];
	// �ʼ�Ŀ�λ
	int piti = begin;
	while (begin < end)
	{
		// �ұ���С���ߵĿ�,���λ���γ��µĿ�
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end];
		piti = end;

		// ����Ҵ���ұߵĿ�,���λ���γ��µĿ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[piti] = a[begin];
		piti = begin;
	}

	a[piti] = key;
	return piti;
}

// ��������ǰ��ָ�뷨
int QuickSortPoint(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	// ����ȡ�з����Ż�
	int midi = GetMinIndex(a, begin, end);
	Swap(&a[begin], &a[midi]);

	while (cur <= end)
	{
		// curλ�õ�ֵС��keyiλ�õ�ֵ
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

//int CallCount = 0;
void QuickSort(int* a, int begin, int end)
{
	//CallCount++;
	// ���䲻����,����ֻ��һ��ֵ������Ҫ��������
	if (begin > end)
	{
		return;
	}

	if (end - begin > 15)
	{
		//int keyi = QuickSortHoare(a, begin, end);
		//int keyi = QuickSortPotholing(a, begin, end);
		int keyi = QuickSortPoint(a, begin, end);
		// [begin, keyi-1]  keyi  [keyi, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = QuickSortPoint(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi);
		}
	}

	StackDistory(&st);
}

void _MergeSort(int *a, int begin, int end, int *tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	// ���εݹ�,������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	// �鲢
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// �ѹ鲢�����ݿ���ԭ����
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// �鲢����ݹ�ʵ��
void MergeSort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			// Խ���߽�����
			//if (end1 >= n)
			//{
			//	end1 = n - 1;

			//	// [begin2, end2]����Ϊ�����ڵ�����
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if(end2 >= n)
			//{
			//	end2 = n - 1;
			//}
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			int m = end2 - begin1 + 1;
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * m);
		}
		//memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

// ��������
	void CountSort(int* a, int n)
	{
		int min = a[0];
		int max = a[0];

		for (int i = 0; i < n; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
			}
			if (a[i] > max)
			{
				max = a[i];
			}
		}

		int range = max - min + 1;
		int* count = (int*)malloc(sizeof(int) * range);
		assert(count);
		memset(count, 0, sizeof(int) * range);

		// ͳ�ƴ���
		for (int i = 0; i < n; i++)
		{
			count[a[i] - min]++;
		}

		// ��д - ����
		int j = 0;
		for (int i = 0; i < range; i++)
		{
			while (count[i]--)
			{
				a[j++] = i + min;
			}
		}
	}