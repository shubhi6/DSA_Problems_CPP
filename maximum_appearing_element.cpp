#include <iostream>
using namespace std;

int maximumOccurredElement(int l[], int r[], int n)
{
    int freq[100]={0};
    for (int i = 0; i < n; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            freq[j]++;
        }
    }
    int res = 0;
    for (int i = 0; i < 100; i++) {
        if (freq[i] > freq[res])
            res = i;
    }
    cout<<"Maximum appearing elements is = ";
    return res;
}

int main()
{
	int j,n,L[n],R[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of 1st array = ";
	for(j=0;j<n;j++)
	cin>>L[j];
	cout<<"Enter elements of 2nd array = ";
	for(j=0;j<n;j++)
	cin>>R[j];
	
    cout << maximumOccurredElement(L, R, n) << endl;
    return 0;
}
