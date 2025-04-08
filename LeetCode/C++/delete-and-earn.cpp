class Solution {
    private:
        const int MM = 1e4+3;
    public:
        int deleteAndEarn(vector<int>& nums) {
            vector<int> cnt(MM, 0);
            for (int x : nums) {cnt[x]++;}
            for (int i = 1; i < MM; i++) {
                cnt[i] *= i;
            }
    
            int a = cnt[0], b = cnt[1];
            for (int i = 2; i < MM; i++) {
                swap(a, b);
                b = max(a, b+cnt[i]);
            }
    
            return b;
        }
    };