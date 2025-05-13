#include <iostream>
#include <string>

using namespace std;

string runLengthEncode(string s) {
    string result = "";
    int count = 1;
    for (int i = 1; i <= s.size(); i++) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1] + to_string(count);
            count = 1;
        }
    }
    return result;
}

int main() {
    string s = "aaabbbcc";
    cout << runLengthEncode(s) << endl;
    return 0;
}
