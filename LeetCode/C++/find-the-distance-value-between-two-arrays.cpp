class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;
        for (auto& x : arr1) {
            for (auto& y : arr2) {
                int a = abs(x-y);
                if (a <= d) {
                    ++ret;
                    break;
                }
            }
        }

        return arr1.size() - ret;
    }
};