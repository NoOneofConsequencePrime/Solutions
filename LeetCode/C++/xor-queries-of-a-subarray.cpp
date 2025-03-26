class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); i++) {
            arr[i] ^= arr[i-1];
        }
        vector<int> ret;
        for (vector<int> v : queries) {
            if (v[0] == 0) {
                ret.push_back(arr[v[1]]);
            } else {
                ret.push_back(arr[v[1]]^arr[v[0]-1]);
            }
        }

        return ret;
    }
};