#include<iostream>
using namespace std;

int ispowerof2(int n)
{
	if(n==0)
	return 0; // 0= false or no and 1= true or yes
	else
	return ((n & n-1)==0);
}


int main()
{
	int n;
	cin>>n;
	cout<<ispowerof2(n)<<endl;
}

