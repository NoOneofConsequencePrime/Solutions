typedef long long ll;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ret = 0;
        int n = nums.size();
        vector<int> sufM(n, 0);
        for (int i = n-1, m = 0; i >= 0; i--) {
            m = max(m, nums[i]);
            sufM[i] = m;
        }
    
        for (int i = 1, m = 0; i < n-1; i++) {
            m = max(m, nums[i-1]);
            ret = max(ret, (ll)(m-nums[i])*sufM[i+1]);
        }

        return ret;
    }
};