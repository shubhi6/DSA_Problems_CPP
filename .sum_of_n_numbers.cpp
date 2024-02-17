//sum of n natural numbers

#include<iostream>
using namespace std;
int main()
{
    int i,n,sum;
    cout<<"Enter the natural numbers" ;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            sum+=i;
        }
    cout<<sum<<"\n";
    return 0;
}

// EXAMPLE :

// INPUT: 5
// OUTPUT: 15
// EXPLANATION: 1+2+3+4+5=15
    
// INPUT: 6
// OUTPUT: 21
// EXPLANATION: 1+2+3+4+5+6=21
