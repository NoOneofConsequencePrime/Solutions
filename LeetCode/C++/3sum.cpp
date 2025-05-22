class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            
            vector<vector<int>> ret;
            for (int i = 0; i < n; i++) {
                if (i == 0 || nums[i] != nums[i-1]) {
                    int l = i+1, r = n-1;
                    while (l < r) {
                        int sum = nums[l]+nums[r]+nums[i];
                        if (sum < 0) {
                            l++;
                        } else if (sum > 0) {
                            r--;
                        } else {
                            ret.push_back({nums[i], nums[l], nums[r]});
                            do {
                                l++;
                            } while (l < r && nums[l] == nums[l-1]);
                        }
                    }
                }
            }
    
            return ret;
        }
};