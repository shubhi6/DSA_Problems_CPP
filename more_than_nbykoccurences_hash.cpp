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
