/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include <iostream>

using namespace std;

bool findSequence(int arr[], int n)
{
    for (int k = n - 1; k >= 0; k--)
    {
        int i = 0;
        int j = k - 1;

        while (i < j)
        {
            int sum = arr[i] + arr[j];

            if (sum == arr[k])
            {
                cout << i+1 << ", " << j+1 << ", " << k+1 << endl;
                return true;
            }
            else if (sum < arr[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    cout << "No sequence found." << endl;
    return false;
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

        findSequence(arr, n);
    }

    return 0;
}
