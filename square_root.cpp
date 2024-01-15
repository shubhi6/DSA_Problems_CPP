// Given an integer X, find its square root. If X is not a perfect square, then return floor(√x).

// Examples : 

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2.

// Input: x = 11
// Output: 3
// Explanation:  The square root of 11 lies in between 3 and 4 so floor of the square root is 3.

#include<iostream>
using namespace std;

int sqrt(int x)
{
	int low=0,high=x,ans=-1;
	while(low<=high)
	{
		int mid=(high+low)/2;
		int msq= mid*mid;
		if(msq==x)
		return mid;
		 if(msq>x)
		 high=mid-1;
		 else
		 {
		   	low=mid+1;
		    ans=mid;
		 }
		
	}
	return ans;
}

int main()
{
	int x;
	cout<<"Enter the number = ";
	cin>>x;
    cout<<"Square Root of the number is = ";
	cout<<sqrt(x);
}
