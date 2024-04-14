// ...............................N-Queen Problem.................

// Let us discuss N Queen as another example problem that can be solved using backtracking. 
// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

#include <bits/stdc++.h>
using namespace std;

#define N 4

int board[N][N];

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int row, int col)
{

    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveRec(int col)
{
    if (col == N)
        return true;

    for (int i = 0; i < N; i++) {

        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveRec(col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solve()
{
    if (solveRec(0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {

	solve();
    return 0;

}

// Output:
//  0  0  1  0 
//  1  0  0  0 
//  0  0  0  1 
//  0  1  0  0 


// Naive Algorithm 
// Generate all possible configurations of queens on board and print a configuration that satisfies the given constraints.

// while there are untried configurations
// {
//    generate the next configuration
//    if queens don't attack in this configuration then
//    {
//       print this configuration;
//    }
// }
 

// Backtracking Algorithm 
// The idea is to place queens one by one in different columns, starting from the leftmost column. 
// When we place a queen in a column, we check for clashes with already placed queens.
// In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. 
// If we do not find such a row due to clashes, then we backtrack and return false.

// 1) Start in the leftmost column
// 2) If all queens are placed
//     return true
// 3) Try all rows in the current column. 
//    Do following for every tried row.
//     a) If the queen can be placed safely in this row 
//        then mark this [row, column] as part of the 
//        solution and recursively check if placing
//        queen here leads to a solution.
//     b) If placing the queen in [row, column] leads to
//        a solution then return true.
//     c) If placing queen doesn't lead to a solution then
//        unmark this [row, column] (Backtrack) and go to 
//        step (a) to try other rows.
// 4) If all rows have been tried and nothing worked,
//    return false to trigger backtracking.
 
