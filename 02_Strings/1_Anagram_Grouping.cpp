#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (auto& str : strs) {
        string temp = str;
        sort(temp.begin(), temp.end());
        map[temp].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& entry : map) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    for (auto& group : result) {
        for (auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
