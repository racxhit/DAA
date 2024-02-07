/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

// Using Algorithm

#include <iostream>
#include <algorithm>
using namespace std;

int countDuplicates(int arr[], int n, int key) 
{
    int count = 0;
    
    int* lower = lower_bound(arr, arr + n, key);
    int* upper = upper_bound(arr, arr + n, key);

    if (lower != upper) 
    {
        count = upper - lower;
    }

    return count;
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

        int key;
        cin >> key;

        int duplicates = countDuplicates(arr, n, key);
        if (duplicates > 0) 
        {
            cout << key << " " << duplicates << endl;
        } 
        else 
        {
            cout << "Key not present" << endl;
        }
    }

    return 0;
}
