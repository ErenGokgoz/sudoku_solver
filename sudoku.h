#pragma once
#include<stdio.h>
#include<stdlib.h>


extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Sudoku {
	struct Square*** squares;
	struct Box** boxes;
}Sudoku;

typedef struct Box {
	struct Square** squares;
	int numbers;
	int possiblty[9];
	int solvable;	
	struct Box* next;
}Box;

typedef struct Square {
	int number;
	/*000000000
	  987654321*/
	int possible[9];
	int solvable;
	Box * box;
	int row;
	int column;	
}Square;

int** createPuzzle();
void printPuzzle(Square*** puzzle);
Sudoku * setUpPuzzle(int** puzzle);
Sudoku* createSudoku(Square *** puzzle, Box** boxes);
int checkPuzzle(Square***,Box ** boxes);
int solveSquare(Square* square);
int updateSudoku(Square*** sudoku, int row, int column);
int checkRows(Square*** sudoku, Box** boxes);
//int solveEvil(Square*** sudoku, Box ** boxes);
/*box functions*/
Box** createBoxes();
int updateBox(Square*** sudoku, int row, int column);
int boxSingles(Square*** sudoku, Box** boxes);
