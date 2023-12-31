#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> v;
    for (int i = 0; i < mat.size(); i++) {
        v.push_back({lower_bound(mat[i].begin(), mat[i].end(), 0, greater<int>())-mat[i].begin(), i});
    }
    sort(v.begin(), v.end());

    vector<int> ret;
    for (int i = 0; i < k; i++) ret.push_back(v[i].second);

    return ret;
}

int main() {
    vector<vector<int>> v = {{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1}};
    vector<int> ans = kWeakestRows(v, 3);
    for (auto& x : ans) cout << x << " ";

    return 0;
}