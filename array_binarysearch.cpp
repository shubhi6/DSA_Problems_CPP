//binary search of array
#include<iostream>

using namespace std;
    int binary_search(int k,int array[],int key)

    {
        int s=0;
        int e=k;
        while(s<=e){
                int mid=(s+e)/2;

                if(array[mid]==key){
                    return mid+1;
                }

            else if(array[mid]>key)

                {e=mid-1;}
            else{s=mid+1;}
        }
    return -1;
    }

// driver code

int main()
{
   int k;
   cin>>k;


     int array[k];
     for( int i=0;i<k;i++){
        cin>>array[i];

     }

    int key;
    cin>>key;

    cout<<binary_search(k,array,key)<<endl;

}
