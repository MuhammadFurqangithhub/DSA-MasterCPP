#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    // Stack contains unmatched parentheses
    return st.size();
}

int main() {
    string s = "())";
    int result = minAddToMakeValid(s);
    cout << "Minimum parentheses to add to make valid: " << result << endl;

    return 0;
}
