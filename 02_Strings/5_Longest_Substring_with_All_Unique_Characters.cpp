#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int longestUniqueSubstring(string s) {
    unordered_set<char> set;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); ++right) {
        while (set.find(s[right]) != set.end()) {
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << longestUniqueSubstring(s) << endl;
    return 0;
}
