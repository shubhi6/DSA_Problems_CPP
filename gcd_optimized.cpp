#include<iostream>
#include<math.h>
using namespace std;

int GCD(int n,int m)
{
		if(m==0)
		return n;
		else
		return GCD(m,n%m);
}

int main()
{
    int t;
    cout<<"Number of Test Cases = ";
    cin>>t;
    while(t--)
    {
    		int n,m;
	        cout<<"Enter Two Number = ";
           	cin>>n>>m;
          	cout<<"GCD of Numbers = " <<GCD(n,m)<<endl;
	}
	return 0;
}
