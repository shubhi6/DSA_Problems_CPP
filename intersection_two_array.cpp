#include<iostream>
#include<algorithm>
using namespace std;

void intersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
	{
		if(i>0 && a[i]==a[i-1])
		{
			i++;
			continue;
		}
        if (a[i] > b[j])
            j++;
        else if (b[j] > a[i]) 
            i++;
        else 
		{
            // when both are equal
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int j, n, x, m;
    cout << "Enter size of 1st array = ";
    cin >> n;
    cout << "Enter elements of 1st array = ";
    int a[n];
    for (j = 0; j < n; j++)
        cin >> a[j];

    cout << "Enter size of 2nd array = ";
    cin >> m;
    cout << "Enter elements of 2nd array = ";
    int b[m];
    for (j = 0; j < m; j++)
        cin >> b[j];
    
    cout << "\nIntersection of arrays = ";
    intersection(a, b, n, m);

    return 0;
}

