#include <iostream>
using namespace std;

#define N 4

void print(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;
    }
    int startRow = row - row % 2, startCol = col - col % 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return 0;
        }
    }

    return 1;
}

int solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return 1;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 4; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return 1;
        }

        grid[row][col] = 0;
    }
    return 0;
}

int main() {
    int grid[N][N] = {
        {1, 0, 0, 0},
        {0, 2, 3, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "No solution exists" << endl;

    return 0;
}
