#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void firstNonRepeating(string s) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char c : s) {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front();
        } else {
            cout << "#";
        }
    }
    cout << endl;
}

int main() {
    string s = "aabcdeff";
    firstNonRepeating(s);
    return 0;
}
