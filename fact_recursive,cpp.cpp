// Recursive implementation to calculate factorial of a number

#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==0)
	return 1;
	return  n*fact(n-1);
	
}
// driver code
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
