#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ZAlgorithm(string s) {
    int n = s.size();
    vector<int> Z(n, 0);
    Z[0] = n;

    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            Z[i] = min(right - i + 1, Z[i - left]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > right) {
            left = i;
            right = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    string s = "aabcaabxaaaz";
    vector<int> result = ZAlgorithm(s);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
