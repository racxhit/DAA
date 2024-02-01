/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/

#include<iostream>

using namespace std;

bool binarySearch(int arr[], int low, int high, int key, int& comparisons) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (arr[mid] == key) 
        {
            return true; 
        } 
        else if (arr[mid] < key) 
        {
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1; 
        }
    }
    return false; 
}

bool isPresent(int arr[], int n, int key, int& comparisons) 
{
    return binarySearch(arr, 0, n - 1, key, comparisons);
}

int main()
{
    int T; 
    cin >> T;

    while (T--) 
    {
        int n; 
        cin >> n;
        int* arr = new int[n]; 
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }

        int key; 
        cin >> key;

        int comparisons = 0; 
        bool found = isPresent(arr, n, key, comparisons);

        if (found) 
        {
            cout << "Present" << endl;    
        }
        else 
        {
            cout << "Not Present" << endl;
        }

        cout << "Number of comparisons: " << comparisons << endl;

        delete[] arr; 
    }

    return 0;
}
