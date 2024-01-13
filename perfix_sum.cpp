#include <bits/stdc++.h>
using namespace std;

void fillPrefix( int arr[], int preArray[], int n ) {
	preArray[0] = arr[0];
  
  	for( int i = 1; i < n; i++ ) {
    	preArray[i] = preArray[ i - 1 ] + arr[i];
    }
}
int main() {

  	int n = 6;
  	int arr[n] = { 3, 6, 2, 8, 9, 2 };
  	
  	int preArray[n];
  
  	fillPrefix( arr, preArray, n );
  	
  	int q = 4;
  	int queries[q][2]  = { { 2, 3 }, { 4, 6 }, { 1, 5 }, { 3, 6 } };
  	
  	for( int i = 0; i < q; i++ ) {
    	int l = queries[i][0] - 1;
      	int r = queries[i][1] - 1;
      
      	if( l - 1 > 0 ) {
          cout<< preArray[r] - preArray[l - 1]<<" ";
        } else {
          cout<< preArray[r]<<" ";
        }
      	
    }
  
    return 0;
}
