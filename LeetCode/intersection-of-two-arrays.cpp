class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool chk[1001] = {};
        for (int x : nums1) {chk[x] = true;}
        vector<int> ret;
        for (int x : nums2) {
            if (chk[x]) {
                ret.push_back(x);
                chk[x] = false;
            }
        }

        return ret;
    }
};