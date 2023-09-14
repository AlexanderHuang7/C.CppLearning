#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>


#define COL 3
#define ROW 3
#define PRINTN printf("\n");
#define ISWIN if(is_win(board, ROW, COL) != 'C') \
              {\
                  break;\
              }

// ��ʼ������
void BoardInit(char board[ROW][COL], int row, int col);

// ��ӡ����     
void DisplayBoard(char board[ROW][COL], int row, int col);

// �������         
void player_move(char board[ROW][COL], int row, int col);

// ��������
void computer_move(char board[ROW][COL], int row, int col);

// �ж���Ӯ
char is_win(char board[ROW][COL], int row, int col);