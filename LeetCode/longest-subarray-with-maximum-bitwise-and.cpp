class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<int, pii> ppi;
    typedef pair<ll, ll> pll;
    #define f first
    #define s second

    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), last = -1;
        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i]&nums[i-1]) < mx) {
                if (last != -1) {
                    ret = max(ret, i-1-last+1);
                    last = -1;
                }
            } else if ((nums[i]&nums[i-1]) == mx) {
                if (last == -1) {
                    last = i-1;
                }
                if (i == nums.size()-1) {
                    ret = max(ret, i-last+1);
                }
            }
        }

        return ret;
    }
};