/*
Given an unsorted array of positive integers, design an algorithm and implement it
using a program to find whether there are any duplicate elements in the array or not.
(use sorting) (Time Complexity = O(n log n))
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string hasDuplicates(vector<int>& arr) 
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] == arr[i + 1]) 
        {
            return "YES"; 
        }
    }

    return "NO"; 
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

        string result = hasDuplicates(arr);

        cout << result << endl;
    }

    return 0;
}

