class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
    
            int ret = 0;
            if (nums[0] < k) {return -1;}
            if (nums[0] > k) {ret++;}
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i-1]) {continue;}
                if (nums[i] < k) {return -1;}
                if (nums[i] > k) {ret++;}
            }
    
            return ret;
        }
    };