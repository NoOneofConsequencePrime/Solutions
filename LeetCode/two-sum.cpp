#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v; for (int i = 0; i < nums.size(); i++) v.push_back({nums[i], i});
    sort(v.begin(), v.end());
    for (int i = 0, j = v.size()-1;;) {
        if (v[i].first+v[j].first == target) return {v[i].second, v[j].second};
        else if (v[i].first+v[j].first > target) j--;
        else i++;
    }
}

int main() {
    vector<int> in = {2, 7, 11, 15};
    vector<int> out = twoSum(in, 9);
    for (auto& x : out) cout << x << " ";

    return 0;
}