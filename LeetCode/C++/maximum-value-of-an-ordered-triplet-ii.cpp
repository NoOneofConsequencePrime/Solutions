typedef long long ll;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        int vi = nums[0], vd = nums[0]-nums[1];
        ll ret = max(0ll, (ll)vd*nums[2]);
        for (int k = 3; k < n; k++) {
            vi = max(vi, nums[k-2]);
            vd = max(vd, vi-nums[k-1]);
            ret = max(ret, (ll)vd*nums[k]);
        }

        return ret;
    }
};