#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // Remove remaining digits if k > 0
    while (!st.empty() && k--) {
        st.pop();
    }

    // Build the result string
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    // Remove leading zeroes
    int non_zero = 0;
    while (non_zero < result.size() && result[non_zero] == '0') {
        non_zero++;
    }

    result = result.substr(non_zero);

    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;

    string smallest = removeKdigits(num, k);
    cout << "Smallest number after removing " << k << " digits: " << smallest << endl;

    return 0;
}
