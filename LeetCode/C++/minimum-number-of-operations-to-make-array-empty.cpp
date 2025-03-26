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

int minOperations(vector<int>& nums) {
    for (int x : nums) mp[x]++;

    int ret = 0;
    for (auto& [f, s] : mp) {
        if (s == 1) return -1;
        ret += s/3 + (s%3 != 0);
    }

    return ret;
}

int main() {
    vector<int> v = {2,3,3,2,2,4,2,3,4};
    cout << minOperations(v);

    return 0;
}