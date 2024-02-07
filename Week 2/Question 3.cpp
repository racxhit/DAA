/*
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/

#include <iostream>
using namespace std;

int countPairsWithDifference(int arr[], int n, int key) 
{
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] - arr[i] == key || arr[i] - arr[j] == key) 
            {
                count++;
            }
        }
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

        int count = countPairsWithDifference(arr, n, key);
        cout << count << endl;
    }

    return 0;
}
