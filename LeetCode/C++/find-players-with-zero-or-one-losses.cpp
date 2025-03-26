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

const int MM = 1e5+2;
int cnt[MM];

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    memset(cnt, -0x3f, sizeof(cnt));
    for (auto &v : matches) {
        int f = v[0], s = v[1];
        if (cnt[f] < 0) {cnt[f] = 0;}
        if (cnt[s] < 0) {cnt[s] = 0;}
        cnt[s]++;
    }

    vector<int> retA, retB;
    for (int i = 1; i < MM; i++) {
        if (cnt[i] == 0) {retA.push_back(i);}
        if (cnt[i] == 1) {retB.push_back(i);}
    }

    return {retA, retB};
}

int main() {

    return 0;
}