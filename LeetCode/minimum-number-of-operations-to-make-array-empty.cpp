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

int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size(), ret = 0, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i-1]) {
            if (cnt == 1) return -1;
            ret += cnt/3 + (cnt%3 != 0);
            cnt = 1;
        } else cnt++;
    }

    if (cnt == 1) return -1;
    ret += cnt/3 + (cnt%3 != 0);

    return ret;
}

int main() {
    vector<int> v = {2,3,3,2,2,4,2,3,4};
    cout << minOperations(v);

    return 0;
}