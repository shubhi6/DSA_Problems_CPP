A palindrome is a word, phrase, number, or other sequences of characters which reads the same forward and backward (ignoring spaces, punctuation, and capitalization). 

EXAMPLE:
INPUT: Enter a string : hujjuh
OUTPUT: hujjuh is a palindrome

INPUT: Enter a string : kokookok
OUTPUT: kokookok is a palindrome

INPUT: Enter a string : shut
OUTPUT: shut is not palindrome


#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string input) {
    for (int i = 0; i < input.length(); i++) {
        if(input[i] != input[input.length() - i - 1])
            return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (isPalindrome(input)) {
        cout << input << " is a palindrome" << endl;
    } else {
        cout << input << " is not a palindrome" << endl;
    }
    return 0;
}
