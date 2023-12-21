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

int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ret = 0, mx = 1;
    for (int i = 1; i < nums.size(); i++, ++mx) {
        if (nums[i]-nums[i-1] != 1 || i == nums.size()-1) {
            ret = max(ret, mx);
            mx = 0;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(v);

    return 0;
}