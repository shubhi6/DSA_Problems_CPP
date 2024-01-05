// through this code we can check whether the kth bit of the number in binary form is set or not

#include<iostream>
using namespace std;

int iskthset(int n, int k)
{
	int x=(1<<(k-1));
	if((n&x)!=0)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
}


int main()
{
	int k,n;
	cout<<"enter a number = ";
	cin>>n;
	cout<<"enter the bit = ";
	cin>>k;
	cout<<iskthset(n,k)<<endl;
}

