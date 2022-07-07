#include "sudoku.h"
#include<iostream>

Sudoku* createSudoku(Square *** squares, Box** boxes) {
	Sudoku* sudoku;
	sudoku = (Sudoku*)malloc(sizeof(Sudoku));

	sudoku->squares = squares;
	sudoku->boxes = boxes;

	return sudoku;
}


int updateSudoku(Square*** sudoku, int row, int column) {
	int x;
	int number = sudoku[row][column]->number;

	for (x = 0; x < SIZE_ROWS; x++) {
		if (sudoku[x][column]->possible[(number - 1)] == 0) {
			sudoku[x][column]->solvable--;
		}
		sudoku[x][column]->possible[(number - 1)] = 1;
	}
	for (x = 0; x < SIZE_COLUMNS; x++) {
		if (sudoku[row][x]->possible[(number - 1)] == 0) {
			sudoku[row][x]->solvable--;
		}
		sudoku[row][x]->possible[(number - 1)] = 1;
	}
	return 1;
}

Sudoku * setUpPuzzle(int** puzzle) {
	Square*** sudoku;
	Box** boxes;
	int i, j, x;
	int currentBox = 0;	

	sudoku = (Square***)malloc(sizeof(Square**) * 9);
	boxes = createBoxes();	

	for (i = 0; i < SIZE_ROWS; i++) {
		sudoku[i] = (Square**)malloc(sizeof(Square*) * 9);
		for (j = 0; j < SIZE_COLUMNS; j++) {
			sudoku[i][j] = (Square*)malloc(sizeof(Square));

			sudoku[i][j]->number = puzzle[i][j];

			sudoku[i][j]->row = i;
			sudoku[i][j]->column = j;

			sudoku[i][j]->solvable = 9;
			for (x = 0; x < SIZE_ROWS; x++) {
				sudoku[i][j]->possible[x] = 0;
			}
			boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
			sudoku[i][j]->box = boxes[currentBox];
			boxes[currentBox]->numbers++;

			if (j == 2) {
				currentBox++;
			}
			else if (j == 5) {
				currentBox++;
			}
			
		}
		currentBox -= 2;
		if (i == 2) {
			currentBox = 3;
		}
		else if (i == 5) {
			currentBox = 6;
		}
	}

	for (i = 0; i < SIZE_COLUMNS; i++) {
		for (j = 0; j < SIZE_COLUMNS; j++) {
			if (sudoku[i][j]->number != 0) {
				sudoku[i][j]->solvable = 0;
				updateSudoku(sudoku, i, j);
				updateBox(sudoku , i, j);
				UNSOLVED--;
			}
		}
	}
	return createSudoku(sudoku, boxes);
}

int checkPuzzle(Square*** sudoku,Box **  boxes) {
	int i, j, x;

	for (i = 0; i < SIZE_COLUMNS; i++) {
		for (j = 0; j < SIZE_COLUMNS; j++) {
			if (sudoku[i][j]->solvable == 1) {
				solveSquare(sudoku[i][j]);
				updateSudoku(sudoku, i, j);
				updateBox(sudoku, i, j);
			}
		}
	}
	
	if (boxSingles(sudoku, boxes)) {
		return 1;
	}
	
	return checkRows(sudoku,boxes);

}

int ** createPuzzle() {
	int** puzzle;
	int i, j;
	int arr[9][9]=
	{   {0,3,4,  0,0,0,  8,0,0},
		{1,0,5,  8,0,3,  0,0,0},
		{0,0,0,  0,4,0,  0,0,6},

		{0,0,0,  0,2,8,  7,0,0},
		{9,5,0,  0,0,0,  0,8,4},
		{0,0,8,  1,9,0,  0,0,0},

		{8,0,0,  0,7,0,  0,0,0},
		{0,0,0,  5,0,9,  3,0,8},
		{0,0,3,  0,0,0,  4,9,0} };

	puzzle = (int**)malloc(sizeof(int*) * 9);

	for (i = 0; i < SIZE_ROWS; i++) {
		puzzle[i] = (int*)malloc(sizeof(int) * 9);
		for (j = 0; j < SIZE_COLUMNS; j++) {
			puzzle[i][j] = arr[i][j];
		}
	}

	return puzzle;
}
void printPuzzle(Square*** puzzle) {
	int i, j;
	printf("-------------------------\n");
	for (i = 0; i < 9; i++) {
		printf("|");
		for (j = 0; j < 9; j++) {
			std::cout << " " << puzzle[i][j]->number;
			if ((j + 1) % 3 == 0) {
				printf(" |");
			}
		}
		printf("\n");
		if ( (i+1) % 3 == 0) {
			printf("-------------------------\n");
		}
    }
}
