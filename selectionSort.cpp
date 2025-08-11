#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i; // declare and initialize here
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
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

    // array sorting function
    selectionSort(arr, n);

    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    };

    return 0;
}
