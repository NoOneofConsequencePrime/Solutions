#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

static bool cmp(string& a, string& b) {return a.length() < b.length();}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    unordered_map<string, int> um;
    for (string& str : words) um[str] = 1;

    int ret = 1;
    for (int i = words.size()-1; i >= 0; i--) {
        string str = words[i];
        for (int j = 0; j < str.length(); j++) {
            string tmp = str.substr(0, j) + str.substr(j+1, str.length()-j-1);
            if (um.count(tmp) != 0) {
                um[tmp] = max(um[tmp], um[str]+1);
                ret = max(ret, um[tmp]);
            }
        }
    }

    return ret;
}

int main() {
    vector<string> v = {"a","b","ba","bca","bda","bdca"};
    cout << longestStrChain(v);

    return 0;
}