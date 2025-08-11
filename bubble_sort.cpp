#include <iostream> 
using namespace std;

int main()
{ 
    int n;
     cout << "Enter array size  at least 10 : ";
    cin >> n;
    int arr[n];

    cout << "Enter Unsorted numeric values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    cout << "Sorted array :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


/* 
Input : 
Enter at least 10 numeric values:
10
Enter Unsorted numeric values: 
1 5 6 100 540 5 1 2 5 9

Output :
Sorted array :
1 1 2 5 5 5 6 9 100 540  
*/