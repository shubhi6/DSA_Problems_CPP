// Given a number of pages in N different books and K students. The books are arranged in ascending order of the number of pages.
// Every student is assigned to read some consecutive books.
// The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 

// Example : 

// Input : pages[] = {12, 34, 67, 90} , K = 2

// Output : Minimum number of pages = 113

// Explanation: There are 2 number of students. Books can be distributed in following fashion : 
// 1) [12] and [34, 67, 90]
// Max number of pages is allocated to student ‘2’ with 34 + 67 + 90 = 191 pages
// 2) [12, 34] and [67, 90] Max number of pages is allocated to student ‘2’ with 67 + 90 = 157 pages 
// 3) [12, 34, 67] and [90] Max number of pages is allocated to student ‘1’ with 12 + 34 + 67 = 113 pages
// Of the 3 cases, Option 3 has the minimum pages = 113.

#include<iostream>
using namespace std;

bool isfeasible(int arr[],int n,int k,int ans)
{
	int req=1,sum=0;
	for(int i=0;i<n;i++)
	{
		if(sum+arr[i]>ans)
		{
			req++;
			sum=arr[i];
		}
	    else
		sum+=arr[i];	
    }
    return(req<=k);
}

int minPages(int arr[],int n, int k)
{
	int sum=0,mx=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		mx=max(mx,arr[i]);
    }
    int low=mx,high=sum,res=0;
    while(low<=high)
    {
		int mid=(high+low)/2;
		if(isfeasible(arr,n,k,mid))
	    {
	    	res=mid;
	    	high=mid-1;
		}
		else
		low=mid+1;
	}
	return res;
}

int main()
{
	int j,n,k;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the number of students = ";
	cin>>k;
   cout<<"Minimum number of pages = ";
	cout<<minPages(arr,n,k);
}
