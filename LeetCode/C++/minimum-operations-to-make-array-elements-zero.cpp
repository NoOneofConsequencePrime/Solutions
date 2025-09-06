typedef long long ll;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<int> pows;
        for (ll i = 1; i <= 1e9; i*=4) {
            pows.push_back(i);
        }

        ll ret = 0;
        for (auto& q : queries) {
            ll sum = 0;
            for (int p : pows) {
                if (q[0] <= p && q[1] >= p) {sum += q[1]-p+1;}
                if (q[0] > p && q[1] >= p) {sum += q[1]-q[0]+1;} 
            }

            if (q[0] == q[1]) {ret += sum;}
            else {ret += (sum+1)/2;}
        }

        return ret;
    }
};