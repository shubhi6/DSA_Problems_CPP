// Calculating LCM of a number

#include<iostream>
#include<math.h>
using namespace std;

int LCM(int n,int m)
{
	int res= max(m,n);
	while(true)
	{
		if(res%n==0 && res%m==0)
		return res;
        res++;
	}
	return res;
	
}

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
