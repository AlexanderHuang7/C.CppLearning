#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

// 图书信息数量
#define ADM 4
// 读者信息数量
#define READ 3
// 结构体数组的最大值
#define MAXSIZE 100

// 管理员菜单
void AdminMenu();
// 管理员界面
void admin();

// 用户菜单
void UserMenu();
// 用户界面
void user();

