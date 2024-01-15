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
