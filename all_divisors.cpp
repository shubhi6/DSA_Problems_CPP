#include<iostream>
#include<math.h>
using namespace std;

void alldivisors(int n)
{
	 int i;
	for (i=1; i*i<n; i++) {
		if (n%i == 0)
			cout<<i<<" ";
	}
	if (i-(n/i)== 1) {
		i--;
	}
	for (;i>=1;i--) {
		if (n%i== 0)
			cout<<n/i<<" ";
	}
	 
}

int main()
{
    		int t;
    		cout<<"ENTER NUMBER OF TEST CASES = ";
    		cin>>t;
    		while(t--)
    		{
    			 int n;
	             cout<<"\n Enter a Number = ";
           	     cin>>n;
          	     alldivisors(n);
			}
	return 0;
}
