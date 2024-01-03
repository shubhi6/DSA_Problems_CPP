// calculation of (LCM) least common multiple of two numbers

#include<iostream>
#include<math.h>
using namespace std;

int GCD(int n,int m)
{
		if(m==0)
		return n;
		else
		return GCD(m,n%m);
}

int LCM(int n,int m)
{
	return (n*m)/GCD(n,m);
	
}
// driver code
int main()
{
    int t;
    cout<<"Number of Test Cases = ";
    cin>>t;
    while(t--)
    {
    		int n,m;
	        cout<<"Enter Two Number = ";
           	cin>>n>>m;
          	cout<<"LCM of Numbers = " <<LCM(n,m)<<endl;
	}
	return 0;
}
