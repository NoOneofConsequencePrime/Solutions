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
    for (int i = 0, j = nums.size()-1; i < j; i++) {
        while (j >= 0 && nums[j]%2) j--;
        if (i >= j) break;
        if (nums[i]%2) {
            swap(nums[i], nums[j]);
            j--;
        }
    }

    return nums;
}

int main() {
    vector<int> v = {0, 1, 2};
    vector<int> ans = sortArrayByParity(v);
    for (int&x : ans) cout << x << " ";

    return 0;
}