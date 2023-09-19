#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int jump(vector<int>& nums) {
    int i = nums.size()-1, ret = 0;
    while (i > 0) {
        for (int j = 0; j < i; j++) {
            if (nums[j] >= i-j) {
                i = j; ret++;
                break;
            }
        }
    }

    return ret;
}

int main() {
    vector<int> v = {2,3,0,1,4};
    cout << jump(v);

    return 0;
}