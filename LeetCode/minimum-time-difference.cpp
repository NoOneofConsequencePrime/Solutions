class Solution {
public:
    int TFH = 1440;
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (string str : timePoints) {
            int time = p(str[0])*600+p(str[1])*60+p(str[3])*10+p(str[4]);
            v.push_back(time); v.push_back(time+TFH);
        }
        sort(v.begin(), v.end());

        int ret = 2e5;
        for (int i = 1; i < v.size(); i++) {
            ret = min(ret, v[i]-v[i-1]);
        }

        return ret;
    }

    int p(char c) {
        return c-'0';
    }
};