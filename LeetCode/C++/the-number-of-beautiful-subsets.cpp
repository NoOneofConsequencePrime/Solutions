class Solution {
    private:
        int st[1005];
        int fun(vector<int>& v, int pos, int k, bool val) {
            if (pos >= v.size()) {// end con
                return val;
            }
            int ret = 0;
            bool left = v[pos]-k >= 1? st[v[pos]-k] == 0 : true;
            bool right = v[pos]+k <= 1000? st[v[pos]+k] == 0 : true; 
            if (left && right) {
                st[v[pos]]++;
                ret += fun(v, pos+1, k, true);
                st[v[pos]]--;
            }
            ret += fun(v, pos+1, k, val);
            return ret;
        }
    public:
        int beautifulSubsets(vector<int>& nums, int k) {
            return fun(nums, 0, k, false);// arr, pos, k, valid or not?
        }
    };