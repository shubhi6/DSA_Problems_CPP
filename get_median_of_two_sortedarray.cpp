#include <iostream>
#include <climits>  // Include the necessary header for INT_MAX and INT_MIN
using namespace std;

int getmed(int arr1[], int n1, int arr2[], int n2)
{
    int b1 = 0, e1 = n1;
    while (b1 <= e1)
    {
        int i1 = (b1 + e1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
        int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];

        int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
        int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            else
                return (double)max(max1, max2);
        }

        else if (max1 > max2)
            e1 = i1 - 1;
        else
            b1 = i1 + 1;
    }
}

int main()
{
    int j, n1, n2;
    cout << "Enter size of 1st array = ";
    cin >> n1;
    cout << "Enter elements of 1st array = ";
    int arr1[n1];
    for (j = 0; j < n1; j++)
        cin >> arr1[j];  // Corrected array name

    cout << "Enter size of 2nd array = ";
    cin >> n2;
    cout << "Enter elements of 2nd array = ";
    int arr2[n2];
    for (j = 0; j < n2; j++)
        cin >> arr2[j];  // Corrected array name

    cout << "Median of two sorted arrays is = ";
    cout << getmed(arr1, n1, arr2, n2);  // Removed square brackets
    return 0;
}

