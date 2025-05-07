#include <iostream>
#include <cmath>
using namespace std;

void swapIfGreater(int arr1[], int arr2[], int idx1, int idx2) {
    if (arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}

void merge(int arr1[], int n, int arr2[], int m) {
    int gap = ceil((n + m) / 2.0);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < (n + m)) {
            // i in arr1 and j in arr1
            if (i < n && j < n) {
                if (arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            }
            // i in arr1 and j in arr2
            else if (i < n && j >= n) {
                swapIfGreater(arr1, arr2, i, j - n);
            }
            // i in arr2 and j in arr2
            else if (i >= n && j >= n) {
                if (arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
            }

            i++, j++;
        }

        if (gap == 1)
            gap = 0;
        else
            gap = ceil(gap / 2.0);
    }
}

int main() {
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, n, arr2, m);

    cout << "Merged arrays:\n";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    for (int i = 0; i < m; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
