//calculating whether the number is prime or not

#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int n)
{
	 if(n<=1)
	 return false;
 	 if(n==2||n==3)
	 return true;
     if (n % 2 == 0 || n % 3 == 0)
	 return false;
	 for(int i=5;i<=sqrt(n);i=i+6)
	   if(n%i==0||n%(i+2)==0)
	     return false;	
	
	return true; 
}

int main()
{
    		int n;
	        cout<<"Enter a Number ";
           	cin>>n;
          	isprime(n) ? cout << "true\n" : cout << "false\n";
	return 0;
}
