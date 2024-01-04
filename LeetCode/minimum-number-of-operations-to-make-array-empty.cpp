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

unordered_map<int, int> mp;
vector<int> n;

int minOperations(vector<int>& nums) {
    for (int x : nums) {
        if (mp.count(x) == 0) {
            mp[x] = 1;
            n.push_back(x);
        } else mp[x]++;
    }

    int ret = 0;
    for (int x : n) {
        if (mp[x] == 1) return -1;
        ret += mp[x]/3 + (mp[x]%3 != 0);
    }

    return ret;
}

int main() {
    vector<int> v = {2,3,3,2,2,4,2,3,4};
    cout << minOperations(v);

    return 0;
}