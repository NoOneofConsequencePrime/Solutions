#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

bool canJump(vector<int>& nums) {
    int i = nums.size()-1;
    while (i != 0) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (i-j <= nums[j]) {
                i = j;
                flag = false;
            }
        }
        
        if (flag) return false;
    }

    return true;
}

int main() {
    vector<int> v = {3,2,1,0,4};
    cout << canJump(v);

    return 0;
}