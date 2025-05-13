#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
    int i = 0, result = 0, sign = 1;
    while (i < str.size() && str[i] == ' ') i++;

    if (i < str.size() && str[i] == '-') {
        sign = -1;
        i++;
    } else if (i < str.size() && str[i] == '+') {
        i++;
    }

    while (i < str.size() && isdigit(str[i])) {
        int digit = str[i] - '0';
        if (result > (INT_MAX - digit) / 10) return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + digit;
        i++;
    }

    return sign * result;
}

int main() {
    string s = "  -42";
    cout << myAtoi(s) << endl;
    return 0;
}
