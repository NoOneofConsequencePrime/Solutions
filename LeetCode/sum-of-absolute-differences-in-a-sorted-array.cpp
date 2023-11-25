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
    vector<int> psa; psa.push_back(nums[0]);
    for (int i = 1; i < n; i++) psa.push_back(psa[i-1]+nums[i]);

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        if (i < n-1) sum += psa[n-1]-psa[i]-(nums[i]*(n-i-1));
        if (i > 0) sum += (nums[i]*(i+1))-psa[i];

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