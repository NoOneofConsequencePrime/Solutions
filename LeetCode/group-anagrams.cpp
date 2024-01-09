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
    sort(strs.begin(), strs.end());

    vector<vector<string>> ret;
    for (int i = 1; i < n; i++) {
        if (strs[i] != strs[i-1]) {
            vector<string> tmp;
            for (string& str : um[strs[i-1]]) tmp.push_back(str);
            ret.push_back(tmp);
        }
    }
    vector<string> tmp;
    for (string& str : um[strs[n-1]]) tmp.push_back(str);
    ret.push_back(tmp);

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