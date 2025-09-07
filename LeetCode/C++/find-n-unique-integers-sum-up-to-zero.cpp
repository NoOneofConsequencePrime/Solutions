class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        for (int i = 0; i < n/2; i++) {
            ret.push_back(i+1);
            ret.push_back(-(i+1));
        }
        if (n%2) {ret.push_back(0);}

        return ret;
    }
};