#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int jump(vector<int>& nums) {
    int ret = 0, mx = 0, i = 0;
    while (i < nums.size()) {
        ret++;
        int tmp = mx;
        for (; i <= tmp && i < nums.size(); i++) {
            mx = max(mx, i+nums[i]);
        }
    }

    return ret-1;
}

int main() {
    vector<int> v = {2,3,0,1,4};
    cout << jump(v);

    return 0;
}