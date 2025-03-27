typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
private:
    pii getDom(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ma = INT_MIN;
        for (auto x : nums) {
            mp[x]++;
            if (mp[ma] < mp[x]) {ma = x;}
        }

        return {ma, mp[ma]};
    }
    bool isDom(int n, int idx, int cnt, int total) {
        return (idx+1)/2 < cnt && (n-idx-1)/2 < (total-cnt);
    }
public:
    int minimumIndex(vector<int>& nums) {
        pii ma = getDom(nums);

        for (int i = 0, cnt = 0; i < nums.size()-1; i++) {
            if (nums[i] == ma.f) {
                cnt++;
                if (isDom(nums.size(), i, cnt, ma.s)) {
                    return i;
                }
            }
        }

        return -1;
    }
};