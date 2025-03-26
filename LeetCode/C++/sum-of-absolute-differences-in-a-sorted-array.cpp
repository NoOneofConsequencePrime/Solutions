#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) nums[i] += nums[i-1];

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        if (i < n-1) sum += nums[n-1]-nums[i]-(i==0? nums[i]:nums[i]-nums[i-1])*(n-i-1);
        if (i > 0) sum += (nums[i]-nums[i-1])*(i+1)-nums[i];

        ret.push_back(sum);
    }

    return ret;
}

int main() {
    vector<int> v = {1,4,6,8,10};
    vector<int> ans = getSumAbsoluteDifferences(v);
    for (int x : ans) cout << x << " ";

    return 0;
}