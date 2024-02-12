#include<iostream>
using namespace std;

//..................ITERATIVE SOLUTION.....................

bool issub(string s1, string s2, int n, int m) 
{
    if (n < m)
      return false;
      for (int i = 0; i <= n - m; ++i) 
    	{
           int j;
           for (j = 0; j < m; ++j) 
		   {
               if (s1[i + j] != s2[j])
                break;
           }
            if (j == m)
            return true;
    }
    return false;
}

//....................RECURSIVE SOLUTION.....................

bool issub(string s1,string s2,int n,int m)
{
	if(m==0)
	return true;
	if(n==0)
	return false;
	if(s1[n-1]==s2[m-1])
	return issub(s1,s2,n-1,m-1);
	else
	return issub(s1,s2,n-1,m);
}

//..........DRIVER CODE...........
int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int n = s1.length();
    int m = s2.length();
    

    if (issub(s1, s2, n, m))
        cout << "Substring found";
    else
        cout << "Substring not found";

    return 0;
}
