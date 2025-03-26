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

bool uniqueOccurrences(vector<int>& arr) {
    int cnt[2001] = {0};
    for (int x : arr) cnt[x+1000]++;
    int cntcnt[1001] = {0};
    for (int i = 0; i <= 2000; i++) {
        if (!cnt[i]) continue;
        cntcnt[cnt[i]]++;
        if (cntcnt[cnt[i]] > 1) return false;
    }

    return true;
}

int main() {
    vector<int> v = {1,2,2,1,1,3};
    cout << uniqueOccurrences(v);

    return 0;
}