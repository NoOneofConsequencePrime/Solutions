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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int findP(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {return -1;}
    int l = 0, r = n-1;
    while (l < r-1) {
        int m = (l+r)/2;
        if (nums[m]<nums[l]) {
            r = m;
        } else if (nums[r]<nums[m]) {
            l = m;
        } else {break;}
    }

    return (l==0 && nums[0]<nums[1])? -1 : l;
}

int search(vector<int>& nums, int target) {
    int m = findP(nums);
    int lb = lower_bound(nums.begin(), nums.begin()+m+1, target)-nums.begin(), ub = upper_bound(nums.begin(), nums.begin()+m+1, target)-nums.begin();
    if (lb != ub) {return lb;}
    lb = lower_bound(nums.begin()+m+1, nums.end(), target)-nums.begin(), ub = upper_bound(nums.begin()+m+1, nums.end(), target)-nums.begin();
    if (lb != ub) {return lb;}

    return -1;
}

int main() {
    vector<int> v = {4,5,6,7,0,1,2};
    cout << search(v, 0);

    return 0;
}