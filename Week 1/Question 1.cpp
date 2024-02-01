/*
Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/

#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key, int& comparisons) 
{
    for (int i = 0; i < n; i++) 
    {
        comparisons++;
        if (arr[i] == key) 
        {
            return true;
        }
    }
    return false; 
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
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
        bool found = linearSearch(arr, n, key, comparisons);

        if (found) 
        {
            cout << "Present" << endl;
        } else {
            cout << "Not Present" << endl;
        }

        cout << "Number of comparisons: " << comparisons << endl;

        delete[] arr;
    }

    return 0;
}
