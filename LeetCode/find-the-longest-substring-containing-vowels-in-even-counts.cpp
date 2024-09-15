class Solution {
public:
    int findTheLongestSubstring(string s) {
        int cnt[5], last[32];
        int ret = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(last, -0x3f, sizeof(last));
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {cnt[0]++;}
            else if (s[i] == 'e') {cnt[1]++;}
            else if (s[i] == 'i') {cnt[2]++;}
            else if (s[i] == 'o') {cnt[3]++;}
            else if (s[i] == 'u') {cnt[4]++;}

            int tmp = 0;
            for (int j = 0; j < 5; j++) {
                tmp <<= 1;
                if (cnt[j]%2) {tmp |= 1;}
            }
            if (tmp == 0) {ret = max(ret, i+1);}

            if (last[tmp] < 0) {last[tmp] = i;}
            else {
                ret = max(ret, i-last[tmp]);
            }
        }

        return ret;
    }
};