//code to calculate count digits of a number

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
 	    int res=0;
 	    while(n>0)
 	     {
 		    n=n/10;
 		    res++;
	      }
	      cout<<res<<endl;
	 }
	 return 0;
 }
