// Set Matrix Zeroes

//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

//You must do it in place.

//Example 1:

//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]


//Example 2:

//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        std::vector<bool> rowZero(m, false);
        std::vector<bool> colZero(n, false);
        
        // Mark rows and columns with zero elements
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        
        // Set entire rows and columns to zero
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rowZero[i] || colZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

