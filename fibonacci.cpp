// number of fibbonacci digits existing in a n long series

#include<iostream>
using namespace std;

int fib(int n)
{
	if(n==0||n==1)
	return n;
	int a=0; int b=1,c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;	
	}
	return c;
}

int main()
{
	int t;
	cout<<"ENTER NUMBER OF TEST CASES = ";
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"\n Enter a number = ";
		cin>>n;
		cout<<fib(n)<<endl;
	}
	return 0;
}
