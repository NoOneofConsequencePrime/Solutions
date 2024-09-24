class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        return max(fun(arr1, arr2), fun(arr2, arr1));
    }

    int fun(vector<int> &a, vector<int> &b) {
        int ret = 0;
        
        unordered_set<int> ust;
        for (int x : a) {
            while (x) {
                ust.insert(x);
                x /= 10;
            }
        }

        for (int x : b) {
            while (x) {
                if (ust.count(x) != 0) {
                    ret = max(ret, (int)log10(x)+1);
                    break;
                }
                x /= 10;
            }
        }

        return ret;
    }
};