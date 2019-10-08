#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

const int N = 15;       //15*15的棋盘
const char ChessBoard = ' ';
const char flag[2] = { 'X','O' };
int now = 1;

char _ChessBoard[N + 1][N + 1];  //棋盘


typedef struct Position {
	int row;        //行
	int col;        //列
}Position;

Position pos;

void InitChessBoard() {          //初始化棋盘
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			_ChessBoard[i][j] = ChessBoard;
		}
	}
}

void PrintChessBoard()
{        //打印棋盘
	printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");
	printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
	for (int i = 1; i < N + 1; ++i)
	{
		printf("%2d ", i);
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", _ChessBoard[i][1], _ChessBoard[i][2], _ChessBoard[i][3], _ChessBoard[i][4], _ChessBoard[i][5], _ChessBoard[i][6], _ChessBoard[i][7], _ChessBoard[i][8], _ChessBoard[i][9], _ChessBoard[i][10], _ChessBoard[i][11], _ChessBoard[i][12], _ChessBoard[i][13], _ChessBoard[i][14], _ChessBoard[i][15]);
		printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
	}
	cout << endl;
}

void ComputerChess()
{
	// TODO
}

void PlayChess()
{
	PrintChessBoard();
	while (1) {
		printf("It %d turn to input a potision: ", now);

		cin >> pos.row >> pos.col;

		if (Judgelegal(pos) == 1)
		{
			_ChessBoard[pos.row][pos.col] = flag[now];
			break;
		}
		cout << "Your input is not legal. Please input a new position: ";
	}
}

int Judgelegal(const Position& pos)
{
	if (pos.row > 0 && pos.row <= N && pos.col > 0 && pos.col <= N) {
		if (_ChessBoard[pos.row][pos.col] == ChessBoard) {
			return 1;
		}
	}
	return 0;
}

int JudgeVictory()
{
	// TODO
}

int GetVictory() {
	int result = JudgeVictory();
	if (result == 1)
	{

	}
	else if (result == 0)
	{

	}
	else
	{

		return 0;
	}
}

int ChoiceMode() {           //选择模式
	system("cls");
	//系统调用，清屏
	InitChessBoard();       //重新初始化棋盘
	cout << "*************************************************" << endl;
	cout << "******************0、退出************************" << endl;
	cout << "******************1、电脑VS玩家******************" << endl;
	cout << "******************2、玩家VS玩家******************" << endl;
	cout << "*************************************************" << endl;
	while (1) {
		int i = 0;
		cout << "请选择模式：";
		cin >> i;
		if (i == 0) {       //退出
			exit(1);
		}
		if (i == 1 || i == 2) {
			return i;
		}
		else {
			cout << "非法输入，请重新输入！" << endl;
		}
	}
}

void Play() {
	Position pos;
	int mode = ChoiceMode();
	while (1)
	{
		if (mode)
		{
			while (1)
			{
				now = 1;
				ComputerChess();
				if (GetVictory()) {
					break;
				}
				now = 2;
				PlayChess();
				if (GetVictory()) 
				{
					break;
				}
			}
		}
		else
		{
			while (1)
			{
				PlayChess();
				if (GetVictory())
				{
					break;
				}
				if (now == 1) now = 2;
				else now = 1;
			}
		}
	}
}



int main()
{
	Play();
	system("pause");
	return 0;
}
