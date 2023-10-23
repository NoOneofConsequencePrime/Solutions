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

int minOperations(vector<int>& nums) {
    int len = nums.size(), ret = len;
    sort(nums.begin(), nums.end());
    for (int a = 0, b = 0, rep = 0; b < nums.size(); b++) {
        while (b > a && nums[b]-nums[a] >= len) {
            if (nums[a] == nums[a+1]) rep--;
            a++;
        }
        if (b != 0 && nums[b] == nums[b-1]) rep++;
        ret = min(ret, len-(b-a+1)+rep);
    }

    return ret;
}

int main() {
    vector<int> v = {1,10,100,1000};
    cout << minOperations(v);

    return 0;
}