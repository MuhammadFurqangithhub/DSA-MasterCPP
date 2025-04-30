#include <iostream>
using namespace std;

int removeDuplicates(int* arr, int size) {
    if (size == 0) return 0;

    int* ptr = arr;
    for (int i = 1; i < size; ++i) {
        if (*(ptr) != *(arr + i)) {
            ptr++;
            *ptr = *(arr + i);
        }
    }
    return (ptr - arr + 1);
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
