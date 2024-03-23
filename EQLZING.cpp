// A man has two integers A and B. In one operation he can choose any integer d, and make one of the following two moves :
//  1. Add d to A and subtract d from B.
//  2. Add d to B and subtract d from A.
// He is allowed to make as many operations as he wants. Can he make A and B equal?
//total test cases taken are 2
//input         //output
//3 3              yes
//1 2              no

// A man has two integers A and B. In one operation he can choose any integer d, and make one of the following two moves :
//  1. Add d to A and subtract d from B.
//  2. Add d to B and subtract d from A.
// He is allowed to make as many operations as he wants. Can he make A and B equal?
//total test cases taken are 2
//input         //output
//3 3              yes
//1 2              no
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;  // total number of test cases
	cin>>t;
	while(t--)
	{
	    int v,b;  // actual solution
	    cin>>v>>b;
	    if(abs(v-b)%2==0)
	    cout<<"yes"<<endl;
	    else
	    cout<<"no"<<endl;
	}

}


