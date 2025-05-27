#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Mock data - M[i][j] = 1 if person i knows person j
vector<vector<int>> M = {
    {0, 1, 1},
    {0, 0, 1},
    {0, 0, 0}
};

bool knows(int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(int n) {
    stack<int> st;

    // Step 1: Push everyone to stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Eliminate until one candidate
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (knows(a, b)) {
            // a can't be celebrity
            st.push(b);
        } else {
            // b can't be celebrity
            st.push(a);
        }
    }

    if (st.empty()) return -1;

    int candidate = st.top();

    // Step 3: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) {
            return -1;
        }
    }

    return candidate;
}

int main() {
    int n = 3;
    int celeb = findCelebrity(n);
    if (celeb == -1) {
        cout << "No Celebrity found.\n";
    } else {
        cout << "Celebrity is person: " << celeb << endl;
    }
    return 0;
}
