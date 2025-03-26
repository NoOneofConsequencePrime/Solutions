class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        unordered_set<char> st;
        for (char c : allowed) {st.insert(c);}
        for (string str : words) {
            bool flag = true;
            for (char c : str) {
                if (st.count(c) == 0) {
                    flag = false; break;
                }
            }
            ret += flag;
        }

        return ret;
    }
};