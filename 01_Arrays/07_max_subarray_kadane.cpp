#include <iostream>
using namespace std;

int maxSubArray(int* arr, int n) {
    if (n == 0) return 0;

    int maxSoFar = *arr;
    int currSum = *arr;

    for (int i = 1; i < n; ++i) {
        currSum = max(*(arr + i), currSum + *(arr + i));
        maxSoFar = max(maxSoFar, currSum);
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum subarray sum: " << maxSubArray(arr, n) << endl;
    return 0;
}
