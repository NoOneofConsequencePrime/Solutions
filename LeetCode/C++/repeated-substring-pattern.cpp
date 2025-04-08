class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            string tmp = s+s;
            return tmp.substr(1, tmp.length()-2).find(s) != string::npos;
        }
    };