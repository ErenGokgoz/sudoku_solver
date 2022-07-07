#include "sudoku.h"

int checkRows(Square*** sudoku ,Box ** boxes) {
	int i, j, k,z;
	int sum[9];

	for (i = 0; i < 9; i++) {

		for (j = 0; j < 9; j++) {
			sum[j] = 0;
		}

		for (j = 0; j < 9; j++) {
			if (sudoku[i][j]->number != 0)
				continue;

			for (k = 0; k < 9; k++) {
				if (sudoku[i][j]->possible[k] == 0) {
					sum[k]++;
					z = j;
				}
			}
		}

		for (k = 0; k < 9; k++) {
			if (sum[k] == 1) {
				sudoku[i][z]->number = k + 1;
				UNSOLVED--;
				sudoku[i][z]->solvable = 0;

				updateBox(sudoku, sudoku[i][z]->row, sudoku[i][z]->column);
				updateSudoku(sudoku, sudoku[i][z]->row, sudoku[i][z]->column);
			}
		}
	}
	return 0;
}