#include <iostream>
#include <iomanip>
#include <fstream>
#define N 7
using namespace std;
int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };


void displaySolution(int board[N][N]) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << setw(2) << board[x][y] << " ";
		cout << endl;
	}
}

bool isLegal(int x, int y, int board[N][N]) {
	if (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1)
		return true;
	return false;
}

int knightTour(int x, int y, int move, int board[N][N]) {
	int xNext, yNext;
	if (move == N * N) 
		return true;

	for (int k = 0; k < 8; k++) {
		xNext = x + xMove[k];
		yNext = y + yMove[k];
		if (isLegal(xNext, yNext, board)) {
			board[xNext][yNext] = move;
			if (knightTour(xNext, yNext, move + 1, board) == 1)
				return true;
			else
				board[xNext][yNext] = -1;
		}
	}
	return false;
}

bool findKnightTour(int board [N][N] ,int startx, int starty) {
	
	for (int x = 0; x < N; x++)     
		for (int y = 0; y < N; y++)
			board[x][y] = -1;

	board[startx][starty] = 0; 
	if (knightTour(startx, starty, 1, board) == false) {
		cout << "Solution does not exist";
		return false;
	}																																																	
	else
		displaySolution(board);
	return true;
}



int main() {
	int board[N][N];
	findKnightTour(board,0,6);
}