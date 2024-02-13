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
