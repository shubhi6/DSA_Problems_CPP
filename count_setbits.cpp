// through this code we can calculate how many bits of a number are set in its binary form

#include<iostream>
using namespace std;

int countsetbits(int n)
    {
        // Your logic here
        int res=0;
        while(n>0)
        {
           n = n & (n-1);
           res = res +1;;
        }
        return res;
    }
    
    int main()
    {
    	int n;
    	cin>>n;
    	cout<<countsetbits(n)<<endl;
	}
