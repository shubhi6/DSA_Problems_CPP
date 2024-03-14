// Sum of n natural numbers.

// EXAMPLE :

// INPUT: 5
// OUTPUT: 15
// EXPLANATION: 1 + 2 + 3 + 4 + 5 = 15


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


    
