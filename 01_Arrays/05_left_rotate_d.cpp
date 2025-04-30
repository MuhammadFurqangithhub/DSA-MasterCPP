#include <iostream>
using namespace std;

void rotateLeft(int* arr, int n, int d) {
    d %= n;

    auto reverse = [](int* start, int* end) {
        while (start < end) {
            swap(*start, *end);
            start++; end--;
        }
    };

    reverse(arr, arr + d - 1);
    reverse(arr + d, arr + n - 1);
    reverse(arr, arr + n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    rotateLeft(arr, n, d);
    cout << "Array after rotating " << d << " positions: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
