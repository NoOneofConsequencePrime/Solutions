#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int hIndex(vector<int>& citations) {
    int cnt[1002]; memset(cnt, 0, sizeof(cnt));
    for (int& x : citations) cnt[x]++;
    for (int i = sizeof(cnt)/sizeof(cnt[0])-2; i >= 0; i--) cnt[i] += cnt[i+1];
    for (int i = sizeof(cnt)/sizeof(cnt[0])-1; i >= 0; i--) {
        if (cnt[i] >= i) return i;
    }

    return -1;
}

int main() {
    vector<int> v = {3,0,6,1,5};
    cout << hIndex(v);

    return 0;
}