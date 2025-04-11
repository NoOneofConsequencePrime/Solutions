class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> st;
            for (int x : nums) {
                if (x < k) {return -1;}
                st.insert(x);
            }
    
            return st.size() - st.count(k);
        }
    };