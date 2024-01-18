#include <bits/stdc++.h>
using namespace std;

int getInvCount(int a[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				inv_count++;

	return inv_count;

}

int main ()
{
	int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int a[n];
    for (j = 0; j < n; j++)
    cin >> a[j];
    cout << " Number of inversions are "<< getInvCount(a, n);
	return 0;
}
