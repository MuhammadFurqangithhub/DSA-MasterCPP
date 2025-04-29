#include <iostream>
#include <unordered_map>
using namespace std;

// Optimized solution: O(n) using hash map
pair<int, int> twoSum(int arr[], int n, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int complement = target - arr[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[arr[i]] = i;
    }
    return {-1, -1}; // No pair found
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    auto result = twoSum(arr, n, target);
    
    if (result.first != -1)
        cout << "Indices: " << result.first << " and " << result.second << endl;
    else
        cout << "Pair not found\n";

    return 0;
}
