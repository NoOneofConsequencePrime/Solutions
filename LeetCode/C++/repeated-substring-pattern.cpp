repeated-substring-patternclass Solution {
    private:
        bool cmp(const string& a, const string& b) {
            int i = 0;
            for (int j = 0; j < b.length(); i++, j++) {
                if (i >= a.length()) {i = 0;}
                if (a[i] != b[j]) {return false;}
            }
            if (i != a.length()) {return false;}
    
            return true;
        }
    public:
        bool repeatedSubstringPattern(string s) {
            for (int i = 1; i <= s.length(); i++) {
                if (cmp(s.substr(0, i), s.substr(i))) {cout << i; return true;}
            }
            
            return false;
        }
    };