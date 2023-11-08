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

void moveZeroes(vector<int>& nums) {
    int a, b, n = nums.size(); a = b = 0;
    while (true) {
        while (a < n && nums[a] != 0) a++;
        if (a == n) break;
        while (b < n && nums[b] == 0) b++;
        if (b == n) break;
        if (a > b) {
            b++; continue;
        }
        swap(nums[a], nums[b]);
        a++; b++;
    }
}

int main() {
    vector<int> v = {1, 0, 3, 0, 12};
    moveZeroes(v);
    for (auto x : v) cout << x << " ";

    return 0;
}