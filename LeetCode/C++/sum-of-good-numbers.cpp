class Solution {
    public:
        int sumOfGoodNumbers(vector<int>& nums, int k) {
            int ret = 0, n = nums.size();
            for (int i = 0; i < n; i++) {
                bool add = true;
                if (i-k >= 0) {
                    if(nums[i-k] >= nums[i]) {add = false;}
                }
                if (i+k < n) {
                    if (nums[i+k] >= nums[i]) {add = false;}
                }
    
                if (add) ret += nums[i];
            }
    
            return ret;
        }
    };