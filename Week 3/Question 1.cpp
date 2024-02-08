/*
Given an unsorted array of integers, design an algorithm and a program to sort the
array using insertion sort. Your program should be able to find number of comparisons
and shifts ( shifts - total number of times the array elements are shifted from their
place) required for sorting the array.
*/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n, int& comparisons, int& shifts)
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
            comparisons++;
        }
        arr[j + 1] = key;
        shifts++;
    }
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }

        int comparisons = 0, shifts = 0;
        insertionSort(arr, n, comparisons, shifts);

        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Comparisons: " << comparisons << endl;
        cout << "Shifts: " << shifts << endl;
    }

    return 0;
}
