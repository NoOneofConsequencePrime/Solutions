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

void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

int main() {
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    for (auto& x : v) cout << x << " ";

    return 0;
}