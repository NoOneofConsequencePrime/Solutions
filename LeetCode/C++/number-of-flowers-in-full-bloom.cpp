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

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> tmp = people, ord;
    sort(tmp.begin(), tmp.end());
    unordered_map<int, int> um;
    for (int i = 0, a = 0; i < tmp.size(); i++) {
        if (um.count(tmp[i]) == 0) {
            ord.push_back(tmp[i]);
            um[tmp[i]] = a;
            a++;
        }
    }

    int cnt[um.size()+3]; memset(cnt, 0, sizeof(cnt));
    for (auto& v : flowers) {
        if (v[0] > ord[ord.size()-1]) continue;
        int a = lower_bound(ord.begin(), ord.end(), v[0])-ord.begin();
        cnt[a]++;
        if (v[1] > ord[ord.size()-1]) continue;
        int b = upper_bound(ord.begin(), ord.end(), v[1])-ord.begin();
        cnt[b]--;
    }
    for (int i = 1; i < sizeof(cnt)/4; i++) cnt[i] += cnt[i-1];

    vector<int> ret;
    for (auto x : people) ret.push_back(cnt[um[x]]);

    return ret;
}

int main() {
    vector<vector<int>> a = {{19,37},{19,38},{19,35}};
    vector<int> b = {6,7,21,1,13,37,5,37,46,43};
    vector<int> ans = fullBloomFlowers(a, b);
    for (auto& x : ans) cout << x << " ";

    return 0;
}