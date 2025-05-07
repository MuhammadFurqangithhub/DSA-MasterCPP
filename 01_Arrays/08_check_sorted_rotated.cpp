#include <iostream>
using namespace std;

bool isSortedAndRotated(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }

    return (count <= 1);
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(isSortedAndRotated(arr, n))
        cout << "Array is sorted and rotated\n";
    else
        cout << "Array is NOT sorted and rotated\n";

    return 0;
}
