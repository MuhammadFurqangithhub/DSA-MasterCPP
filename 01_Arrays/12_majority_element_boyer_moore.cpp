#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int n) {
    int candidate = -1, count = 0;

    // Phase 1: Find a potential candidate
    for (int i = 0; i < n; ++i) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else {
            count += (arr[i] == candidate) ? 1 : -1;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] == candidate)
            count++;

    return (count > n / 2) ? candidate : -1;
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findMajorityElement(arr, n);
    if (result != -1)
        cout << "Majority Element: " << result << endl;
    else
        cout << "No Majority Element found." << endl;

    return 0;
}
