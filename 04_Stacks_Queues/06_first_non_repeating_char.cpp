#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChar(string stream) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char ch : stream) {
        freq[ch]++;
        q.push(ch);

        // Remove characters from the front of the queue that are repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";  // No non-repeating char at this point
        }
    }
    cout << endl;
}

int main() {
    string stream = "aabc";
    cout << "First non-repeating characters at each point: ";
    firstNonRepeatingChar(stream);
    return 0;
}
