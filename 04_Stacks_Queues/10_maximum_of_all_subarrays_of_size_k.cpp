#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;  // Stores indexes of useful elements for each window
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements out of this window from front
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove smaller elements from the back since they won't be max
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Starting from i >= k-1, add max of window to result
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> max_values = maxSlidingWindow(arr, k);

    cout << "Max of all subarrays of size " << k << ": ";
    for (int val : max_values)
        cout << val << " ";
    cout << endl;

    return 0;
}
