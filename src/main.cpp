#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

const int N = 15;       //15*15������
const char ChessBoard = ' ';
const char flag1 = 'O';
const char flag2 = 'X';
char _ChessBoard[N + 1][N + 1];  //����


typedef struct Position {
	int row;        //��
	int col;        //��
}Position;

void Play() {
	Position play1;
	Position play2;
	while (1)
	{
		//TODO
	}
}

void InitChessBoard() {          //��ʼ������
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			_ChessBoard[i][j] = ChessBoard;
		}
	}
}

int ChoiceMode() {           //ѡ��ģʽ
	system("cls");
	//ϵͳ���ã�����
	InitChessBoard();       //���³�ʼ������
	cout << "*************************************************" << endl;
	cout << "******************0���˳�************************" << endl;
	cout << "******************1������VS���******************" << endl;
	cout << "******************2�����VS���******************" << endl;
	cout << "*************************************************" << endl;
	while (1) {
		int i = 0;
		cout << "��ѡ��ģʽ��";
		cin >> i;
		if (i == 0) {       //�˳�
			exit(1);
		}
		if (i == 1 || i == 2) {
			return i;
		}
		else {
			cout << "�Ƿ����룬���������룡" << endl;
		}
	}
}

void PrintChessBoard() 
{        //��ӡ����
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

void ComputerChess(Position& pos, char flag)
{
		// TODO
}

/*

*/
void PlayChess(Position& pos, int player, char flag)
{
		// TODO
}

int Judgelegal(const Position& pos)
{
		// TODO
}

int JudgeVictory(Position pos, char flag)
{
	// TODO
}

int main()
{
	Play();
	system("pause");
	return 0;
}