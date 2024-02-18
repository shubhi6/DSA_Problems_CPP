// Naive method to calculate (GCD) greatest common divider of two numbers
// The GCD (Greatest Common Divisor) of two or more integers is the largest positive integer that divides each of the integers without leaving a remainder.
// For example, the GCD of 8 and 12 is 4 because 4 is the largest integer that divides both 8 and 12 without leaving a remainder.

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



// EXAMPLES: 

// INPUT : Enter Two Number =  6   9
// OUTPUT : GCD of Numbers = 3
// INPUT : Enter Two Number =  7   9
// OUTPUT : GCD of Numbers = 1
// INPUT : Enter Two Number =  5   15
// OUTPUT : GCD of Numbers = 5
// INPUT : Enter Two Number =  8   4
// OUTPUT : GCD of Numbers = 4
	
