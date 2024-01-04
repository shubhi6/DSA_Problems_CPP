// we can count the  number of digits in a factorial of a number

#include<iostream>
using namespace std;

class Solution {
public:
    int digitsInFactorial(int N) {
        if (N < 0) {
            return 0;  // Factorial is not defined for negative numbers
        }

        // Use long long to avoid integer overflow
        long long factorial = 1;
        for (int i = 2; i <= N; i++) {
            factorial *= i;
        }

        int digitCount = 0;
        while (factorial > 0) {
            factorial /= 10;
            digitCount++;
        }

        return digitCount;
    }
};

int main() {
    Solution sol;
    int N;
    cout << "Enter a number: ";
    cin >> N;
    int result = sol.digitsInFactorial(N);
    cout << "Number of digits in factorial: " << result << endl;

    return 0;
}

