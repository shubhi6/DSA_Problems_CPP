#include<iostream>
using namespace std;

// Define constants for rows and columns
const int R = 3;
const int C = 2;

void print(int mat[R][C]) {
    for (int i = 0; i < R; i++)
	{
        if(i%2==0)
        {
        	for (int j = 0; j < C; j++)
            cout << mat[i][j] << " ";
		}
		
		else
		{
			for (int j = C-1; j>=0 ; j--)
            cout << mat[i][j] << " ";
		}
    }
}

int main() {
    int mat[R][C] = {{10, 20}, {30, 40}, {50, 60}};
    print(mat); // Call the function to print the matrix
    return 0;
}

