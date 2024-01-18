#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int sort(int numbers[], int start, int last) {
    int pivot = numbers[last];
    int index = start - 1;
    int temp = 0;

    for (int i = start; i < last; ++i) {
        if (numbers[i] < pivot) {
            ++index;

            // swap the position
            temp = numbers[index];
            numbers[index] = numbers[i];
            numbers[i] = temp;
        }
    }

    int pivotposition = ++index;

    temp = numbers[index];
    numbers[index] = pivot;
    numbers[last] = temp;

    return pivotposition;
}

void quicksort(int numbers[], int start, int end) {
    if (start < end) {
        int pivot_position = sort(numbers, start, end);
        quicksort(numbers, start, pivot_position - 1);
        quicksort(numbers, pivot_position + 1, end);
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
    // rearrange using lomuto partition
    quicksort(numbers, 0, size - 1);

    print(numbers, size);

    return 0;
}

