//#include "sudoku.h"
//#include <iostream>
//#include <vector>
//
//int solveEvil(Square*** sudoku , Box ** boxes) {
//	int i, j, x, z, a , y;
//	int arr[9] = { 0,0,0,0,0,0,0,0,0 };
//	int row, column;
//	z = 0;
//	for (i = 0; i < 9; i++) {
//		/*loop trough boxes*/
//		for (j = 0; j < 9; j++) {
//			/*loop trough squares*/
//			if (boxes[i]->squares[j]->number != 0)
//				continue;
//			row = boxes[i]->squares[j]->row;
//			column = boxes[i]->squares[j]->column;
//			for (x = 0; x < 9; x++) {
//				if (boxes[i]->squares[j]->possible[x] == 0) {
//					arr[z] = x + 1;
//					z++;
//				}
//			}
//			for (y = 0; y < z; y++) {
//				for (a = (j + 1); a < 9; a++) {//checking front boxes poss
//					if (boxes[i]->squares[a]->possible[(arr[y] - 1)] == 1) {
//
//						boxes[i]->squares[j]->number = arr[y];
//						boxes[i]->squares[j]->solvable = 0;
//						/*updateBox(sudoku, row,column);
//						updateSudoku(sudoku, row,column);*/
//						UNSOLVED--;
//
//						break;
//					}
//				}
//				if (boxes[i]->squares[j]->number != 0) {
//					break;
//				}
//			}
//			if (boxes[i]->squares[j]->number == 0) {
//
//				boxes[i]->squares[j]->number = arr[z -1];
//				boxes[i]->squares[j]->solvable = 0;
//				/*updateBox(sudoku,row, column);
//				updateSudoku(sudoku,row,column);*/
//				UNSOLVED--;
//			}
//		}
//	}
//	return 1;
//}