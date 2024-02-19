Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

Algorithm: areRotations(str1, str2)

    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.


#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool check_rotation(string s, string goal) {
    if (s.size() != goal.size())
        return false;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    
    if (check_rotation(s1, s2))
        cout << s2 << " is a rotated form of " << s1 << endl;
    else
        cout << s2 << " is not a rotated form of " << s1 << endl;
    
    string s3;
    cout << "Enter another string to check rotation: ";
    cin >> s3;
    
    if (check_rotation(s1, s3))
        cout << s3 << " is a rotated form of " << s1 << endl;
    else
        cout << s3 << " is not a rotated form of " << s1 << endl;

    return 0;
}

