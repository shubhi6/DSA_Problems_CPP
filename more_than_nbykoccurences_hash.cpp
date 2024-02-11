//Implementation to find more than N/K occurences using hash.
// Example: 

//Input: arr[8] = { 30 ,10 ,20 ,20 ,10, 20, 30 ,30}
// Key=4
//Output: 20 30
//[NOTE: N=8 and N/K=8/4=2]

//Input: arr[8] = { 30, 10, 20, 30, 30, 40, 30, 40, 30}
// Key=2
//Output: 30
//[NOTE: N=9 and N/K=9/2=4.5]


#include<iostream>
#include<unordered_map>
using namespace std;

void printNbyK(int arr[],int n, int k)
{
  unordered_map<int,int>m;
  for(int i=0;i<n;i++)
  m[arr[i]]++;
  for(auto e:m)
  if(e.second > n/k)
  cout<<e.first<<" ";

}
int main()
{
  int n;
  cout<<"Enter the size of array : ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of array : ";
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int k;
  cout<<"Enter the key : ";
  cin>>k;

  printNbyK(arr,n,k);
  return 0;
}
