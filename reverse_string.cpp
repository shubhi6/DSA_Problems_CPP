



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
