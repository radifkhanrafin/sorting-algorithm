#include <iostream> 
using namespace std;

int main()
{
    int n;
    cout << "Enter array size  at least 10 : " << endl;
    cin >> n;
    if (n < 10)
    {
        cout<<"input at least 10 \n";
        return 0;
    }

    int arr[n];

    cout << "Enter  Sorted numeric values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // o of n 

    int x;
    cout << "Enter the element to search: \n";
    cin >> x;

    // Binary Search
    int left = 0, right = n - 1, index = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (index == -1)
    {
        cout << "Element not found.\n";
    }
    else
    { 

        int startIndex = index, endIndex = index;
        while (startIndex > 0 && arr[startIndex - 1] == x)
            startIndex--;
        while (endIndex < n - 1 && arr[endIndex + 1] == x)
            endIndex++;

        cout << "Element found at positions: " << endl;
        for (int i = startIndex; i <= endIndex; i++)
        {
            cout << i << " ";
        }
        cout << "\nTotal occurrences: " << (endIndex - startIndex + 1) << endl;
    }

    return 0;
}
