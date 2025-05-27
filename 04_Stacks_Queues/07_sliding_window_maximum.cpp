#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, int k) {
    deque<int> dq; // stores indices of useful elements in decreasing order
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements out of this window from front
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Starting to add results after first k elements
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxValues = slidingWindowMaximum(nums, k);
    cout << "Sliding window maximum for each window: ";
    for (int val : maxValues) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
