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

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) nums[i] += nums[i-1];

    if (nums[n-1]-nums[0] == 0) return 0;
    for (int i = 1; i < n-1; i++) {
        if (nums[i-1] == nums[n-1]-nums[i]) return i;
    }
    if (nums[n-2] == 0) return n-1;

    return -1;
}

int main() {
    vector<int> v = {-1,-1,0,1,1,0};
    cout << pivotIndex(v);

    return 0;
}