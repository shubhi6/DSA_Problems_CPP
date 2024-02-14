//Reverse words in a given string
// Let the input string be “i like this program very much”. 
// The function should change the string to “much very program this like i”

// Examples: 

// INPUT: "hello my name is space."
// OUTPUT: "space is name my hello."

// INPUT: "a is the first letter."
// OUTPUT: "letter first the is a."    


#include <iostream>
#include <vector>
using namespace std;

void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }

        else
            str += s[i];
    }
    tmp.push_back(str);
    for (int i = tmp.size() - 1; i > 0; i--)
        cout << tmp[i] << " ";

    cout << tmp[0] << endl;
}

// Driver Code
int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    reverseWords(s);
    return 0;
}
