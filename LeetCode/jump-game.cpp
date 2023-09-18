#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

bool canJump(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i <= j && i < nums.size(); i++) {
        j = max(j, i+nums[i]);
    }

    return j >= nums.size()-1;
}

int main() {
    vector<int> v = {2,3,1,1,4};
    cout << canJump(v);

    return 0;
}