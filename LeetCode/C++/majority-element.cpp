#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> um;
    int n = nums.size();
    for (auto& x : nums) {
        if (++um[x] > n/2) return x;
    }

    return -1;
}

int main() {
    vector<int> a = {2,2,1,1,1,2,2};
    cout << majorityElement(a) << '\n';

    return 0;
}