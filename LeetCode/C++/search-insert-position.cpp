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

int searchInsert(vector<int>& nums, int target) {
    int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin(), ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
    if (lb != ub) return lb;
    else return lb;
}

int main() {
    vector<int> v = {1,3,5,6};
    cout << searchInsert(v, 5);

    return 0;
}