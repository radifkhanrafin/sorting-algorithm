#include <iostream>
using namespace std;

// Manual index-based swap
void manualSwap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // smaller element index

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            manualSwap(arr, i, j);
        }
    }
    manualSwap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {15, 3, 12, 6, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
