#include <iostream>
#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_COLUMNS = 9;
int SIZE_ROWS = 9;
int x;
int main()
{
    int preUnsolved;
    int step = 0;
    Sudoku * sudoku;
    int** puzzle;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    std::cout <<"Unsolved Square: " << UNSOLVED << std::endl;

    while (UNSOLVED != 0) {
        preUnsolved = UNSOLVED;
        checkPuzzle(sudoku->squares,sudoku->boxes);
        step++;
        if (preUnsolved == UNSOLVED) {
            printf("Sudoku Stuck!!!\n");
            break;
        }
    }
    

    std::cout <<"Unsolved: " << UNSOLVED << std::endl;


    printf("\n");
    std::cout << step << std::endl;
    printf("\n");

    printPuzzle(sudoku->squares);

    std::cout << "Unsolved Square: " << UNSOLVED << std::endl;

    return 0;
}

