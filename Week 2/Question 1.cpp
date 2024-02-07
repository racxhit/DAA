/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include <iostream>

using namespace std;

int countDuplicates(int arr[], int n, int key) 
{
    int count = 0;
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key) 
        {
            count++;
            int left = mid - 1;
            int right = mid + 1;

            while (left >= 0 && arr[left] == key) 
            {
                count++;
                left--;
            }

            while (right < n && arr[right] == key) 
            {
                count++;
                right++;
            }

            break;
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
