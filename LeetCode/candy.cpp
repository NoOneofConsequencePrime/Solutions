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

int candy(vector<int>& ratings) {
    vector<pair<int, int>> v;
    for (int i = 0; i < ratings.size(); i++) v.push_back({ratings[i], i});
    sort(v.begin(), v.end());

    int cnt[ratings.size()]; fill(cnt, cnt+ratings.size(), 1);
    for (auto& p : v) {
        if (p.second != 0) {
            if (ratings[p.second] > ratings[p.second-1]) cnt[p.second] = cnt[p.second-1]+1;
        }
        if (p.second != ratings.size()-1) {
            if (ratings[p.second] > ratings[p.second+1]) cnt[p.second] = max(cnt[p.second], cnt[p.second+1]+1);
        }
    }

    int ret = 0;
    for (int& x : cnt) ret += x;
    return ret;
}

int main() {
    vector<int> v = {1,0,2};
    cout << candy(v);

    return 0;
}