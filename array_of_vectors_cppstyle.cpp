//C++ style solution to write a general purpose matrix
// using array of vectors

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr[], int m)
{
    for (int i = 0; i < m; i++) 
	{
        for (int j = 0; j < arr[i].size(); j++) 
		{
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of columns : ";
    cin >> n;

    vector<int> arr[m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i].push_back(i);
        }
    }

    print(arr, m);

    return 0;
}

