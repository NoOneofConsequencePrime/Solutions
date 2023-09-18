#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    for (int i = 0; i < n-k; i++) nums.push_back(nums[i]);
    nums.erase(nums.begin(), nums.begin()+(n-k));
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    rotate(v, 3);
    for (auto& x : v) cout << x << " ";

    return 0;
}