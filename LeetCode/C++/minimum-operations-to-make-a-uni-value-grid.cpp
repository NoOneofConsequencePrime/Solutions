class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v((int)1e4+1, 0);
        int mi = INT_MAX, n = 0;
        for (auto& row : grid) {
            for (auto val : row) {
                v[val]++;
                mi = min(mi, val);
            }
            n += row.size();
        }

        int ret = 0;
        for (int i = 1; i <= 1e4; i++) {
            if (v[i] != 0) {
                if ((i-mi)%x != 0) {return -1;}
                ret += (i-mi)/x * v[i];
            }
        }

        int pre = v[mi];
        for (int i = 1; mi+i*x <= 1e4; i++) {
            int val = mi+i*x;
            int chg = pre - (n-pre);
            if (chg > 0) {break;}
            ret += chg;
            pre += v[val];
        }

        return ret;
    }
};