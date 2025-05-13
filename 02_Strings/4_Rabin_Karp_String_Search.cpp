#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();
    int p = 31, mod = 1e9 + 7;
    vector<int> result;

    long long patternHash = 0, textHash = 0, pPower = 1;

    for (int i = 0; i < m; ++i) {
        patternHash = (patternHash + (pattern[i] - 'a' + 1) * pPower) % mod;
        textHash = (textHash + (text[i] - 'a' + 1) * pPower) % mod;
        if (i != m - 1) pPower = (pPower * p) % mod;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash) {
            result.push_back(i);
        }
        if (i < n - m) {
            textHash = (textHash - (text[i] - 'a' + 1)) % mod;
            textHash = (textHash * p) % mod;
            textHash = (textHash + (text[i + m] - 'a' + 1)) % mod;
        }
    }

    return result;
}

int main() {
    string text = "abcabcabca";
    string pattern = "abc";
    vector<int> result = rabinKarp(text, pattern);

    for (int index : result) {
        cout << "Pattern found at index " << index << endl;
    }
    return 0;
}
