#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// �����ӡ
void SortPrint(int* a, int n);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int QuickSortHoare(int* a, int begin, int end);

// ���������ڿӷ�
int QuickSortPotholing(int* a, int begin, int end);

// ��������ǰ��ָ�뷨
int QuickSortPoint(int* a, int begin, int end);
void QuickSort(int* a, int begin, int end);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);

// ���� 
extern int CallCount;