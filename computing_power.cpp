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
		cout<<"Enter a Number = ";
		cin>>x;
		cout<<"Enter a power = ";
		cin>>n;
		if(n==0)
		return 1;
		int temp = pow(x,(n/2));
		temp=temp*temp;
		if(n%2==0)
		cout<< temp;
		else
		cout<< temp*x;
	}
}
