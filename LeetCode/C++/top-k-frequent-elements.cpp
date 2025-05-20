typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        vector<pii> v;
        for (const auto& pair : mp) {
            v.push_back({pair.s, pair.f});
        }
        sort(v.begin(), v.end());

        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(v[v.size()-1-i].s);
        }

        return ret;
    }
};