#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int i = 0, j = 0;
    while (true) {
        if (i == j && i != 0) break;
        i = nums[i];
        j = nums[nums[j]];
    }

    int prev = -1; i = 0;
    while (true) {
        if (i == j) break;
        prev = i;
        i = nums[i]; j = nums[j];
    }

    return nums[prev];
}

int main() {
    vector<int> v = {1,3,4,2,2};
    cout << findDuplicate(v);

    return 0;
}