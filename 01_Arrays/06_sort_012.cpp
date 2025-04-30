#include <iostream>
using namespace std;

void sortColors(int* arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (*(arr + mid)) {
            case 0: swap(*(arr + low++), *(arr + mid++)); break;
            case 1: mid++; break;
            case 2: swap(*(arr + mid), *(arr + high--)); break;
        }
    }
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortColors(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
