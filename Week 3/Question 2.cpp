/*
Given an unsorted array of integers, design an algorithm and implement a program to
sort this array using selection sort. Your program should also find number of
comparisons and number of swaps required.
*/

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) 
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            comparisons++;
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        if (minIndex != i) 
        {
            swaps++;
            swap(arr[i], arr[minIndex]);
        }
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

        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }

        int comparisons = 0;
        int swaps = 0;

        selectionSort(arr, comparisons, swaps);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;

        cout << "swaps = " << swaps << endl;
    }

    return 0;
}
