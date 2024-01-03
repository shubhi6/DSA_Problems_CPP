// naive method to calculate (GCD) greatest common divider of two numbers

#include<iostream>
#include<math.h>
using namespace std;

int GCD(int n,int m)
{
	int res= min(m,n);
	while(res>0)
	{
		if(n%res==0 && m%res==0)
     	{
           break;
     	}
           res--;
	}
	return res;
	
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
          	cout<<"GCD of Numbers = " <<GCD(n,m)<<endl;
	}
	return 0;
}
