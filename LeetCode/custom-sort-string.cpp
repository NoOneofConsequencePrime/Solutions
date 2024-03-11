class Solution {
public:
    string customSortString(string order, string s) {
        int ord[26] = {};
        for (int i = 0; i < order.length(); i++) {
            ord[order[i]-'a'] = i;
        }

        sort(s.begin(), s.end(), [&](const char &a, const char &b) {
            return ord[a-'a']<ord[b-'a'];
        });

        return s;
    }
};