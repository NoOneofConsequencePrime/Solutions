class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ret;
        unordered_map<string, int> mp1, mp2;

        addWords(s1, mp1); addWords(s2, mp2);

        for (auto const& [key, val] : mp1) {
            if (val == 1 && mp2.count(key) == 0) {ret.push_back(key);}
        }
        for (auto const& [key, val] : mp2) {
            if (val == 1 && mp1.count(key) == 0) {ret.push_back(key);}
        }

        return ret;
    }

    void addWords(string &str, unordered_map<string, int> &mp) {
        int lst = 0;
        while (str.find(" ", lst) != string::npos) {
            int pos = str.find(" ", lst);
            mp[str.substr(lst, pos-lst)]++;
            lst = pos+1;
        }
        mp[str.substr(lst, str.length()-lst+1)]++;
    }
 };