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

bool isMonotonic(vector<int>& nums) {
    int chk = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i-1]) {
            if (chk == -1) return false;
            chk = 1;
        } else if (nums[i] < nums[i-1]) {
            if (chk == 1) return false;
            chk = -1;
        }
    }

    return true;
}

int main() {
    vector<int> v = {1,3,2};
    cout << isMonotonic(v);

    return 0;
}