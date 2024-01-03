// method to trail the zeros in the factorial of a number

#include<iostream>
using namespace std;

int trailing_of_zeros(int n)
{
	int res=0;
	for(int i=5;i<=n;i=i*5)
    res=res+(n/i);
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
    		int n;
	        cout<<"Enter a Number = ";
           	cin>>n;
          	cout<<"ZEROS = " <<trailing_of_zeros(n)<<endl;
	}
	return 0;
}
