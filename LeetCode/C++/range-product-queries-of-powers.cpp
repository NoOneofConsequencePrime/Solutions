typedef long long ll;

class Solution {
private:
    ll M = 1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> dig;
        for (int i = 1; n; i *= 2) {
            if (n%2 == 1) {dig.push_back(i);}
            n /= 2;
        }

        vector<int> ans;
        for (auto& v : queries) {
            ll tmp = 1;
            for (int i = v[0]; i <= v[1]; i++) {
                tmp = (tmp*dig[i])%M;
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};