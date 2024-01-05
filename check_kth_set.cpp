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
	cin>>n;
	cin>>k;
	cout<<iskthset(n,k)<<endl;
}

