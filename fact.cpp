#include<iostream>
using namespace std;

int fact(int n)
{
	int res=1;
	for(int i=2;i<=n;i++)
		res=res*i;
	return res;	
	
}

int main()
{
	int t;
    cout<<"Number of Test Cases = ";
    cin>>t;
    while(t--)
	{
		 int n;
	     cout<<"Enter a Number = ";
	     cin>>n;
      	cout<<"FACTORIAL OF A NUMBER IS = " <<fact(n)<<endl;
	}
	return 0;
}
