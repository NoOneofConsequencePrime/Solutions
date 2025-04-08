class Solution {
    private:
        bool chk[30];
    public:
        int partitionString(string s) {
            int ret = 0;
            memset(chk, 0, sizeof(chk));
            for (char c : s) {
                if (chk[c-'a']) {
                    ret++;
                    memset(chk, 0, sizeof(chk));
                }
                chk[c-'a'] = true;
            }
    
            return ret+1;
        }
    };