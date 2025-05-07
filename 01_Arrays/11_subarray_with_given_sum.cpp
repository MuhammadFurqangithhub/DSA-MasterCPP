#include <iostream>
using namespace std;

bool findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0, end = 0, sum = 0;

    while (end < n) {
        sum += arr[end];

        // Shrink the window if sum exceeds target
        while (sum > target && start <= end)
            sum -= arr[start++];

        if (sum == target) {
            cout << "Subarray found from index " << start
                 << " to " << end << endl;
            return true;
        }

        end++;
    }

    cout << "No subarray with given sum found." << endl;
    return false;
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int target = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubarrayWithSum(arr, n, target);

    return 0;
}
