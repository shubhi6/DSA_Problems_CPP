
#include <bits/stdc++.h>
using namespace std;

#define N 4

bool solveMazeRec(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int i, int j)
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeRec(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}

bool solveMazeRec(int maze[N][N], int i, int j, int sol[N][N])
{
    if (i == N - 1 && j == N - 1 && maze[i][j] == 1)
    {
        sol[i][j] = 1;
        return true;
    }

    if (isSafe(maze, i, j) == true)
    {
        sol[i][j] = 1;

        if (solveMazeRec(maze, i + 1, j, sol) == true)
            return true;

        if (solveMazeRec(maze, i, j + 1, sol) == true)
            return true;

        sol[i][j] = 0;
    }

    return false;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}

 

// Output:
// The 1 values show the path for rat 

//  1  0  0  0 
//  1  1  0  0 
//  0  1  0  0 
//  0  1  1  1 

// Backtracking Algorithm: Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally.
// Solving one piece at a time, and removing those solutions that fail to satisfy the constraints of the problem at any point of time 
// (by time, here, is referred to the time elapsed till reaching any level of the search tree) is the process of backtracking.

// Approach: Form a recursive function, which will follow a path and check if the path reaches the destination or not.
// If the path does not reach the destination then backtrack and try other paths. 

// Algorithm:  

// 1.Create a solution matrix, initially filled with 0’s.
// 2.Create a recursive function, which takes initial matrix, output matrix and position of rat (i, j).
// 3.if the position is out of the matrix or the position is not valid then return.
// 4.Mark the position output[i][j] as 1 and check if the current position is destination or not. If destination is reached print the output matrix and return.
// 5.Recursively call for position (i+1, j) and (i, j+1).
// 6.Unmark position (i, j), i.e output[i][j] = 0.

