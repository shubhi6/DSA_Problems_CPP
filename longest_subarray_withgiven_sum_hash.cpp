#include <iostream>
#include <unordered_map>

using namespace std;

int maxlen(int arr[],int n,int sum)
{
   unordered_map<int,int>m;
   int pre_sum=0,res=0;
   for(int i=0;i<n;i++)
   {
       pre_sum+=arr[i];
       if(pre_sum==sum)
       res=i+1;
       if(m.find(pre_sum)== m.end())
       m.insert({pre_sum,i});
       if(m.find(pre_sum)!= m.end())
       res=max(res,i-m[pre_sum -sum]);

   }
   return res;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout << "Enter the sum: ";
    cin >> sum;

    int result = maxlen(arr, n, sum);
    cout << "Length of longest subarray with sum " << sum << ": " << result << endl;

    return 0;
}


