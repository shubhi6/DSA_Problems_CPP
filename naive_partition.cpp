#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arr[], int start, int high) {
    int pivot = arr[high];
    int index = start;

    for (int i = start; i < high; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[index]);
            ++index;
        }
    }

    std::swap(arr[index], arr[high]);
    return index;
}

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int point = partition(arr, start, end);

        quicksort(arr, start, point - 1);
        quicksort(arr, point + 1, end);
    }
}

int main() {
	
    int size ;
    cout<<"Enter size of array = ";
    cin>>size;
    cout<<"Enter elements of array = ";
    int numbers[size];
    for(int i=0;i<size;i++)
    cin>>numbers[i];

    // rearrange using naive partition
    quicksort(numbers, 0, size - 1);

    print(numbers, size);

    return 0;
}

