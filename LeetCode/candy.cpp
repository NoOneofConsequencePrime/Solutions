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
    if (ratings.size() == 1) return 1;
    int ret = 0;
    int cnt[ratings.size()]; memset(cnt, 0, sizeof(cnt));

    queue<int> q;
    for (int i = 0; i < ratings.size(); i++) {
        if (i > 0 && i < ratings.size()-1 && ratings[i-1] >= ratings[i] && ratings[i] <= ratings[i+1]) {
            q.push(i); cnt[i] = 1; ret++;
        }
        if (i == 0 && ratings[i] <= ratings[i+1]) {
            q.push(i); cnt[i] = 1; ret++;
        } else if (i == ratings.size()-1 && ratings[i] <= ratings[i-1]) {
            q.push(i); cnt[i] = 1; ret++;
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        printf("%d: %d\n", cur, cnt[cur]);
        if (cur > 0 && cnt[cur]+1 > cnt[cur-1] && ratings[cur-1] > ratings[cur]) {
            ret -= cnt[cur-1];
            cnt[cur-1] = cnt[cur]+1;
            ret += cnt[cur-1];
            q.push(cur-1);
        }
        if (cur < ratings.size()-1 && cnt[cur]+1 > cnt[cur+1] && ratings[cur+1] > ratings[cur]) {
            ret -= cnt[cur+1];
            cnt[cur+1] = cnt[cur]+1;
            ret += cnt[cur+1];
            q.push(cur+1);
        }
    }

    return ret;
}

int main() {
    vector<int> v = {1,3,4,5,2};
    cout << candy(v);

    return 0;
}