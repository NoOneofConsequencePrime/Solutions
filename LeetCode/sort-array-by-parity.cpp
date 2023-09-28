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

vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> ret(nums.size());
    for (int i = 0, a = 0, b = nums.size()-1; i < nums.size(); i++) {
        if (nums[i]%2) ret[b--] = nums[i];
        else ret[a++] = nums[i];
    }

    return ret;
}

int main() {
    vector<int> v = {0, 1, 2};
    vector<int> ans = sortArrayByParity(v);
    for (int&x : ans) cout << x << " ";

    return 0;
}