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

// 插入排序
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

// 希尔排序
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
	// gap > 1是预排序
	// gap最后一次等于1,是直接插入排序
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

// 选择排序
// O(N^2)
// 插入排序更好
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

// 堆排序
// 升序建大堆
// 降序建小堆
void AdjustDwon(int* a, int size, int parent)
{
	assert(a);

	int child = parent * 2 + 1;

	while (child < size)
	{
#if 0
		// 小堆
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
		// 大堆
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
	// 建堆
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

// 冒泡排序
// O(N^2) 最好情况O(N)
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

// 三数取中法
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

// 快速排序递归实现
// 快速排序hoare版本
int QuickSortHoare(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		// 右边先走,找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边后走,找大
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

// 快速排序挖坑法
int QuickSortPotholing(int* a, int begin, int end)
{
	int key = a[begin];
	// 最开始的坑位
	int piti = begin;
	while (begin < end)
	{
		// 右边找小填到左边的坑,这个位置形成新的坑
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end];
		piti = end;

		// 左边找大填到右边的坑,这个位置形成新的坑
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

// 快速排序前后指针法
int QuickSortPoint(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	// 三数取中法的优化
	int midi = GetMinIndex(a, begin, end);
	Swap(&a[begin], &a[midi]);

	while (cur <= end)
	{
		// cur位置的值小于keyi位置的值
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
	// 区间不存在,或者只有一个值啧不需要继续处理
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

// 快速排序 非递归实现
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

	// 分治递归,让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	// 归并
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

	// 把归并的数据拷会原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// 归并排序递归实现
void MergeSort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

// 归并排序非递归实现
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

			// 越界后边界修正
			//if (end1 >= n)
			//{
			//	end1 = n - 1;

			//	// [begin2, end2]修正为不存在的区间
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

// 计数排序
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

		// 统计次数
		for (int i = 0; i < n; i++)
		{
			count[a[i] - min]++;
		}

		// 回写 - 排序
		int j = 0;
		for (int i = 0; i < range; i++)
		{
			while (count[i]--)
			{
				a[j++] = i + min;
			}
		}
	}