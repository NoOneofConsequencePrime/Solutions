class Solution {
    private:
        bool chk[102];
    public:
        int minimumOperations(vector<int>& nums) {
            memset(chk, 0, sizeof(chk));
            for (int i = nums.size()-1; i >= 0; i--) {
                if (chk[nums[i]]) {
                    return i/3+1;
                } else {chk[nums[i]] = true;}
            }
    
            return 0;
        }
    };