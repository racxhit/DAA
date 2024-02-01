#include <iostream>
using namespace std;
bool linearSearch(int arr[], int start, int end, int key, int& comparisons) 
{
    for (int i = start; i <= end; i++) 
    {
        comparisons++;
        if (arr[i] == key) 
        {
            return true; 
        }
    }
    return false; 
}

bool jumpSearch(int arr[], int n, int key, int& comparisons) 
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) 
    {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) 
        {
            return false;
        }
    }

    return linearSearch(arr, prev, min(step, n), key, comparisons);
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
        bool found = jumpSearch(arr, n, key, comparisons);

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
