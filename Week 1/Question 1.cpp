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
