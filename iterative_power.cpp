#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t;
	cout<<"ENTER NUMBER OF TEST CASES = ";
	cin>>t;
	while(t--)
	{
		int x,n;
		cout<<"\n Enter a Number = ";
		cin>>x;
		cout<<"\n Enter a power = ";
		cin>>n;
		int res=1;
		while(n>0)
		{
			if(n%2!=0)
			res=res*x;
			x=x*x;
			n=n/2;
		}
		cout<<res<<" ";
	
	}
}
