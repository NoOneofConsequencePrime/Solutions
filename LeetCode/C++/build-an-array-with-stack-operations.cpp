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

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ret;
    for (int i = 0, j = 1; i < target.size(); i++, j++) {
        while (target[i] != j) {
            ret.push_back("Push");
            ret.push_back("Pop");
            j++;
        }
        ret.push_back("Push");
    }

    return ret;
}

int main() {
    vector<int> v = {1, 3};
    vector<string> ans = buildArray(v, 3);
    for (auto x : ans) cout << x << '\n';

    return 0;
}