#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

unordered_map<string, vector<string>> um;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.size() == 1) return {{strs[0]}};
    int n = strs.size();
    for (string& str : strs) {
        string tmp = str;
        sort(str.begin(), str.end());
        um[str].push_back(tmp);
    }

    vector<vector<string>> ret;
    for (auto& [key, v] : um) {
        ret.push_back(v);
    }

    return ret;
}

int main() {
    vector<string> v = {"a", ""};
    vector<vector<string>> ans = groupAnagrams(v);

    for (auto& v : ans) {
        for (auto& str : v) cout << str << " ";
        cout << endl;
    }

    return 0;
}