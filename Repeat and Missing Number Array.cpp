//Repeat and Missing Number Array

//You are given a read only array of n integers from 1 to n.

//Each integer appears exactly once except A which appears twice and B which is missing.

//Return A and B.

//Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

//Note that in your output A should precede B.

//Example:

//Input:[3 1 2 5 3] 

//Output:[3, 4] 

//A = 3, B = 4

#include <vector>
#include <cmath> // for abs

std::vector<int> Solution::repeatedNumber(const std::vector<int>& A) {
    std::vector<int> result(2, -1); // Initialize result vector with -1

    // Make a copy of the input vector A
    std::vector<int> temp(A);

    for (int i = 0; i < temp.size(); ++i) {
        int current = std::abs(temp[i]); // Get absolute value to handle negative numbers
        if (temp[current - 1] > 0) { // If the element is positive
            temp[current - 1] *= -1; // Mark the element as visited by negating it
        } else { // If the element is negative
            result[0] = current; // The current element is the repeated number
        }
    }

    // Find the missing number
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] > 0) { // If the element is positive, it means it was not visited
            result[1] = i + 1; // Missing number is i+1
            break;
        }
    }

    return result;
}

