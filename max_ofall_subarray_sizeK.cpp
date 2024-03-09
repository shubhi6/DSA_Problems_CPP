//...................NAIVE APPROACH.................

#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int N, int K) {
    int j, max;
    for (int i = 0; i <= N - K; i++) {
        max = arr[i];
        for (j = 1; j < K; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
    printKMax(arr, N, K);
    return 0;
}


//................EFFICIENT APPROACH...............
#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int N, int K)
{
    std::deque<int> Qi(K);
    int i;
    for (i = 0; i < K; ++i) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < N; ++i) {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - K)
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << arr[Qi.front()];
}

int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
    printKMax(arr, N, K);
    return 0;
}

