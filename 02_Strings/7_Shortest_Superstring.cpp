#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int overlap(string &a, string &b) {
    int max_overlap = 0;
    for (int i = 1; i <= min(a.size(), b.size()); i++) {
        if (a.substr(a.size() - i) == b.substr(0, i)) {
            max_overlap = i;
        }
    }
    return max_overlap;
}

string shortestSuperstring(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> parent(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dp[i][j] = overlap(words[i], words[j]);
            }
        }
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;

    string res = "";
    for (int i = 0; i < n; i++) {
        res += words[i];
    }

    return res;
}

int main() {
    vector<string> words = {"cat", "cats", "sand", "and", "dog"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}
