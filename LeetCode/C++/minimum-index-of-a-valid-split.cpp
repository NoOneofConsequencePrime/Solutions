typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
private:
    pii getDom(vector<int>& nums) {
        pii tmp = {-1, 0};
        for (auto x : nums) {
            if (x != tmp.f) {
                if (tmp.s == 0) {tmp = {x, 1};}
                else {tmp.s--;}
            } else {tmp.s++;}
        }

        return {tmp.f, count(nums.begin(), nums.end(), tmp.f)};
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