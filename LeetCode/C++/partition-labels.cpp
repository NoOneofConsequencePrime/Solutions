class Solution {
    private:
        int cnt[26];
        bool isHaving[26];
        bool chk() {
            for (int k = 0; k < 26; k++) {
                if (isHaving[k] && cnt[k] != 0) {
                    return false;
                }
            }
    
            return true;
        }
    public:
        vector<int> partitionLabels(string s) {
            vector<int> ret;
            for (auto c : s) {
                cnt[c-'a']++;
            }
    
            for (int i = 0, j = -1; i < s.length(); i++) {
                int c = s[i]-'a';
                isHaving[c] = true;
                cnt[c]--;
                if (cnt[c] == 0) {
                    if (chk()) {
                        ret.push_back(i-j);
                        j = i;
                    }
                }
            }
    
            return ret;
        }
    };