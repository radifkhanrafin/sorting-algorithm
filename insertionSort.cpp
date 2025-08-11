#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    const int n = 10;
    int arr[n];

    cout << "Enter 10 unsorted numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Insertion Sort
    insertionSort(arr, n);

    cout << "Sorted using Insertion Sort: ";

    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    };
    return 0;
}
