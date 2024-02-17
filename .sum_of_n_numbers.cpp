//sum of n natural numbers


#include<iostream>
using namespace std;
int main()
{
    int i,n,sum;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            sum+=i;
        }
    cout<<sum<<"\n";
    return 0;
}

