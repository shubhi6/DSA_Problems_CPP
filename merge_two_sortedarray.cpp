#include<iostream>
#include<algorithm>
using namespace std;

void merge(int a[], int n, int b[], int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < n)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < m)
    {
        cout << b[j] << " ";
        j++;
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

    cout << "\nArray after merging" << "\n";
    merge(a, n, b, m);

    return 0;
}

