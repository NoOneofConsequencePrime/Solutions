class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        unordered_map<int, int> mp;
        int mi = INT_MAX, ma = INT_MIN;
        for (auto& v : grid) {
            for (auto num : v) {
                if (mp.count(num) != 0) {mp[num]++;}
                else {mp[num] = 1;}

                mi = min(mi, num);
                ma = max(ma, num);
            }
        }
        if (mp.size() == 1 && mp[grid[0][0]] == 1) {return 0;}

        for (auto& v : grid) {
            for (auto num : v) {
                if ((num-mi)%x != 0) {return -1;}
            }
        }

        vector<int> pre((ma-mi)/x+1, 0), suf((ma-mi)/x+1, 0);
        for (int num = mi+x, i=1, cnt = 0; num <= ma; num+=x, i++) {
            pre[i] += pre[i-1];
            pre[i] += cnt;
            if (mp.count(num-x) != 0) {
                pre[i] += mp[num-x];
                cnt += mp[num-x];
            }
        }
        for (int num = ma-x, i=(ma-mi)/x-1, cnt = 0; num >= mi; num-=x, i--) {
            suf[i] += suf[i+1];
            suf[i] += cnt;
            if (mp.count(num+x) != 0) {
                suf[i] += mp[num+x];
                cnt += mp[num+x];
            }
        }

        int ret = INT_MAX;
        for (int i = 0; i < pre.size(); i++) {
            ret = min(ret, pre[i]+suf[i]);
        }

        return ret;
    }
};