// Given a string str, find the length of the longest substring without repeating characters. 

// Example:

// For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.

// For “BBBB” the longest substring is “B”, with length 1.

// For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7

#include <bits/stdc++.h>
using namespace std;

int longestSubstrDistinctChars(string s) {
    if (s.length() == 0)
        return 0;
    int n = s.length();
    set<char> st;
    int len = 1;
    st.insert(s[0]);
    int i = 1;
    int maxLen = 0
    while (i < n) {
        if (s[i] != s[i - 1] && st.find(s[i]) == st.end()) {
            st.insert(s[i]);
            len++;
            i++;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            if (len == 1) {
                i++;
            } else {
                st.clear();
                i = i - len + 1;
                len = 0;
            }
        }
    }
    return max(maxLen, len);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int len = longestSubstrDistinctChars(str);
    cout << "The length of the longest non-repeating character substring: " << len;
    return 0;
}

