#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin()+n-k, nums.end());
    reverse(nums.begin(), nums.end());
    reverse(nums.begin()+k, nums.end());
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    rotate(v, 3);
    for (auto& x : v) cout << x << " ";

    return 0;
}