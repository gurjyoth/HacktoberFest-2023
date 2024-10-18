#include <iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;

    // Count elements less than or equal to pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) count++;
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    // Rearranging elements around the pivot
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < arr[pivotIndex]) i++;
        while (arr[j] > arr[pivotIndex]) j--;
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quicksort(int arr[], int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}

int main() {
    int arr[] = {2, 0, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
