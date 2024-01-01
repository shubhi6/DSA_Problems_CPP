//insertion of the element at the end of the array
#include <bits/stdc++.h>
using namespace std;

void insertAtEnd(int arr[],int sizeOfArray,int element);

 
void insertAtEnd(int arr[],int sizeOfArray,int element)
{
    if (sizeOfArray >= 1) {
        arr[sizeOfArray-1] = element;
        sizeOfArray++;
    
}
}



//{ Driver Code Starts.

int main() {
    int t;
    
    //taking testcases
    cin>>t;
    while(t--)
    {
        int sizeOfArray;
        
        //input size of Array
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray-1;i++)
        cin>>arr[i];
        
        //input element to be inserted
        int element;
        cin>>element;
        
        //calling insertAtEnd() function
        insertAtEnd(arr,sizeOfArray,element);
        
        //printing the elements of the array
        for(int i=0;i<sizeOfArray;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
        
    }
    
	return 0;
}

