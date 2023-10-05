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
    int cnt[3]; memset(cnt, 0, sizeof(cnt));
    for (int& x : nums) cnt[x]++;
    fill(nums.begin(), nums.begin()+cnt[0], 0);
    fill(nums.begin()+cnt[0], nums.begin()+cnt[0]+cnt[1], 1);
    fill(nums.begin()+cnt[0]+cnt[1], nums.end(), 2);
}

int main() {
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    for (auto& x : v) cout << x << " ";

    return 0;
}