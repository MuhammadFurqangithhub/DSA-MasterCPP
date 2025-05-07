#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutiveSubsequence(int arr[], int n) {
    unordered_set<int> s;

    // Insert all elements into the set
    for (int i = 0; i < n; ++i)
        s.insert(arr[i]);

    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        // Only check for the beginning of a sequence
        if (s.find(arr[i] - 1) == s.end()) {
            int currentNum = arr[i];
            int count = 1;

            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                count++;
            }

            maxLength = max(maxLength, count);
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of Longest Consecutive Subsequence: "
         << longestConsecutiveSubsequence(arr, n) << endl;

    return 0;
}
