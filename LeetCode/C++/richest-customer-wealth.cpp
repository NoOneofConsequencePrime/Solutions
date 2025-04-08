class Solution {
    public:
        int maximumWealth(vector<vector<int>>& accounts) {
            int ma = INT_MIN;
            for (auto& v : accounts) {
                ma = max(ma, accumulate(v.begin(), v.end(), 0));
            }
    
            return ma;
        }
    };