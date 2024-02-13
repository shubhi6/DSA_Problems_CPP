Problem: Given two strings, check whether two strings are an anagram of each other. 
 Two strings are said to be an anagram of each other if they are just permutations of each other. That is, the set of characters in both the strings must be the same, only the order of characters can be different.

 

Input: string1 = "abcd"
       string2 = "bcad"
Output: Yes

Input: string1 = "listen"
       string2 = "silent"
Output: Yes

#include <iostream>
#include <string>
using namespace std;
#define NO_OF_CHARS 256

bool areAnagram(const string& str1, const string& str2)
{
    int count1[NO_OF_CHARS] = { 0 };
    int count2[NO_OF_CHARS] = { 0 };

    for (char c : str1)
        count1[c]++;
    for (char c : str2)
        count2[c]++;


    for (int i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;

    return true;
}

/* Driver code*/
int main()
{
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1);

    cout << "Enter the second string: ";
    getline(cin, str2);

    if (areAnagram(str1, str2))
        cout << "The two strings are anagrams of each other";
    else
        cout << "The two strings are not anagrams of each other";

    return 0;
}
