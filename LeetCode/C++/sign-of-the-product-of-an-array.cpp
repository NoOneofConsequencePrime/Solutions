class Solution {
    public:
        int arraySign(vector<int>& nums) {
            int cnt = 0;
            for (int x : nums) {
                if (x == 0) {return 0;}
                cnt += (x < 0);
            }
    
            return (cnt%2)? -1 : 1;
        }
    };