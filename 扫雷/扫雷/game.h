#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINENUM 80
#define PRINTN printf("\n");

// ��ʼ��ɨ��
void MineInit(char arr[ROWS][COLS], int rows, int cols, char set);

// ��ӡɨ��
void PrintMine(char arr[ROWS][COLS], int row, int col);

// ������
void SetMine(char arr[ROWS][COLS], int row, int col);

// ɨ��
void MineSweeper(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);