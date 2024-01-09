#include<iostream>
using namespace std;

void toh(int n,char a,char b,char c)
{
	if (n == 0) 
		return;
	
	
	toh(n-1,a,c,b);
	cout<<" move "<<n<<" from "<<a<<" to  "<<c<<endl;
	toh(n-1,b,a,c);
}


int main()
{
	int n; 
	cout<<"enter number of levels = ";
	cin>>n;
	toh(n, 'a', 'c', 'b');
}
