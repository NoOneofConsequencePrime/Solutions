class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for (int x : arr) {
            if (mp.count(x) == 0) {
                mp[x] = 0;
            }
        }

        int i = 1;
        for (auto &[a, b] : mp) {
            b = i++;
        }

        for (int &x : arr) {
            x = mp[x];
        }

        return arr;
    }
};