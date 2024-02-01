/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k]
< key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching)
*/

#include <iostream>
#include <cmath>

using namespace std;

bool linearSearch(int arr[], int s, int e, int key, int& c) 
{
    for (int i = s; i <= e; i++) 
    {
        c++;
        if (arr[i] == key) 
        {
            return true; 
        }
    }
    return false; 
}

bool jumpSearch(int arr[], int n, int key, int& c) 
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) 
    {
        c++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) 
        {
            return false;
        }
    }

    return linearSearch(arr, prev, min(step, n), key, c);
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

        int c = 0; 
        bool found = jumpSearch(arr, n, key, c);

        if (found) 
        {
            cout << "Present" << endl;
        } 
        else 
        {
            cout << "Not Present" << endl;
        }

        cout << "Number of comparisons: " << c << endl;

        delete[] arr; 
    }

    return 0;
}
