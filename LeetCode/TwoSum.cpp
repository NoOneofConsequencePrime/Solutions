#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
        if (um.count(target-nums[i]) > 0) return {um[target-nums[i]], i};
        um[nums[i]] = i;
    }

    return {0};
}

int main() {
    vector<int> in = {2, 7, 11, 15};
    vector<int> out = twoSum(in, 9);
    for (auto& x : out) cout << x << " ";

    return 0;
}