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

int minOperations(vector<int>& nums) {
    int len = nums.size(), ret = len, tmp = 0;
    sort(nums.begin(), nums.end());
    unordered_map<int, int> um;
    for (int a = 0, b = 0; b < len; b++) {
        while (b > a && nums[b] - nums[a] >= len) {
            um[nums[a]]--;
            if (um[nums[a]] == 0) tmp--;
            a++;
        }
        um[nums[b]]++;
        if (um[nums[b]] == 1) tmp++;
        ret = min(ret, len-tmp);
    }

    return ret;
}

int main() {
    vector<int> v = {4,2,5,3};
    cout << minOperations(v);

    return 0;
}