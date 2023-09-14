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

// 初始化棋盘
void BoardInit(char board[ROW][COL], int row, int col);

// 打印棋盘     
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋         
void player_move(char board[ROW][COL], int row, int col);

// 电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

// 判断输赢
char is_win(char board[ROW][COL], int row, int col);