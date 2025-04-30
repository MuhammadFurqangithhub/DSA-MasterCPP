#include <iostream>
using namespace std;

int findSecondLargest(int* arr, int size) {
    if (size < 2) return -1;

    int first = *arr;
    int second = -1;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > first) {
            second = first;
            first = *(arr + i);
        } else if (*(arr + i) < first && (*(arr + i) > second || second == -1)) {
            second = *(arr + i);
        }
    }

    return (second == -1) ? -1 : second;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findSecondLargest(arr, size);
    if (result != -1)
        cout << "Second largest: " << result << endl;
    else
        cout << "No second largest element found." << endl;
    return 0;
}
