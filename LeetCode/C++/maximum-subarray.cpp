class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int ret = nums[0];
            int prev = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                prev = max(prev+nums[i], nums[i]);
    
                ret = max(ret, prev);
            }
    
            return ret;
        }
    };