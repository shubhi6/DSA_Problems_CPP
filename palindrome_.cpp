#include<iostream>
using namespace std;
int main()
{
   int t;
   cout<<"ENTER NUMBER OF TEST CASES = ";
   cin>>t;
   while(t--)
   {
   		int n;
   		cout<<"Enter a Number = ";
    	cin>>n;
	    int rev=0;
	    int temp=n;
     	while(temp!=0)
        	{
	        	int ld=temp%10;
	        	rev=rev*10+ld;
	        	temp=temp/10;
        	}
     	if(rev==n)
    	cout<<"  IS PALINDROME  "<<endl;
    	else
    	cout<<"  IS NOT PALINDROME  "<<endl;
   }
   return 0;
}
