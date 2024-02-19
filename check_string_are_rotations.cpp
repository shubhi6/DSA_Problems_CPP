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

