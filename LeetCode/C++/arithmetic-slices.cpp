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

int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int ret = 0, cnt = 2, chg = nums[1]-nums[0];
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i]-chg == nums[i-1]) cnt++;
        else {
            if (cnt >= 3) ret += ((cnt-2)*(cnt-1))/2;
            cnt = 2; chg = nums[i]-nums[i-1];
        }
    }
    if (cnt >= 3) ret += ((cnt-2)*(cnt-1))/2;

    return ret;
}

int main() {
    vector<int> v = {1,2,3,6,9};
    cout << numberOfArithmeticSlices(v);

    return 0;
}