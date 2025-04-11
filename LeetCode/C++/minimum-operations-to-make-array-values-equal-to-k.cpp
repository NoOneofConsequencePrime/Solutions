class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            bool chk[102]; memset(chk, false, sizeof(chk));
            int mi = INT_MAX, ma = INT_MIN;
            for (int x : nums) {
                chk[x] = true;
                mi = min(mi, x);
                ma = max(ma, x);
            }
    
            if (mi < k) {return -1;}
            if (mi == ma) {
                return !(mi == k);
            } else {
                int cnt = 0;
                for (int i = 1; i <= 100; i++) {cnt += chk[i];}
                return cnt - (mi==k);
            }
        }
    };