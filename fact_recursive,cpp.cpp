#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==0)
	return 1;
	return  n*fact(n-1);
	
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
