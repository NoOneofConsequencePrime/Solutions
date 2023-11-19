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

int reductionOperations(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    sort(nums.begin(), nums.end());
    
    int ret = 0;
    for (int i = nums.size()-2, cnt = 1; i >= 0; i--, cnt++) {
        if (nums[i] != nums[i+1]) ret += cnt;
    }
    
    return ret;
}

int main() {
    vector<int> v = {10,10,10,10,1,10,10,10,10,10};
    cout << reductionOperations(v);

    return 0;
}