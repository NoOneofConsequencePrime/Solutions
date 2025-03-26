class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {return false;}
        int cnt[26];
        for (char c : s1) {cnt[c-'a']++;}
        for (int l = 0, r = 0; r < s2.length(); r++) {
            while (l < r && cnt[s2[r]-'a'] == 0) {
                cnt[s2[l]-'a']++;
                l++;
            }
            if (cnt[s2[r]-'a'] == 0) {l++;}
            else {
                cnt[s2[r]-'a']--;
                if (r-l+1 == s1.length()) {
                    return true;
                }
            }
        }

        return false;
    }
};