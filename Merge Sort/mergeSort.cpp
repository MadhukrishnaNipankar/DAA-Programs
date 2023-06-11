#include <iostream>
using namespace std;

/*


2 10 1 3 7 9 11

2 10 1 3        7 9 11


2 10   1 3       7 9   11


2  10   1  3      7  9   11


2 10     1 3       7 9    11

1 2 3 10            7 9 11


1 2 3 7 9 10 11


Time Complexity: O(n log n)
Space Complexity: O(n)

*/

void merge(int arr[], int size, int low, int mid, int high)
{
    int temp[high - low + 1];
    int tempPtr = 0;

    int i = low, j = mid + 1, k = high;

    while (i < j && j <= k)
    {
        if (arr[i] <= arr[j])
        {
            temp[tempPtr++] = arr[i];
            i++;
        }
        else
        {
            temp[tempPtr++] = arr[j];
            j++;
        }
    }

    while (i < j)
    {
        temp[tempPtr++] = arr[i];
        i++;
    }
    while (j <= k)
    {
        temp[tempPtr++] = arr[j];
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int size, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(arr, size, low, mid);
    mergeSort(arr, size, mid + 1, high);
    merge(arr, size, low, mid, high);
}

int inputArray(int arr[], int size)
{
    cout << "Enter " << size << " array elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int displayArray(int arr[], int size)
{
    cout << "Array Elements are:  " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // int size;
    cout << "Welcome to Merge Sort : " << endl;
    // cout << "Enter the size of array to sort: " << endl;
    int size = 7;
    int arr[size];
    inputArray(arr, size);
    mergeSort(arr, size, 0, size - 1);
    displayArray(arr, size);
    return 0;
}