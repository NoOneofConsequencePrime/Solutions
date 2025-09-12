class Solution {
private:
    bool chk(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        vector<char> v;
        for (char &c : s) {
            if (chk(c)) {
                v.push_back(c);
                c = ' ';
            }
        }
        sort(v.begin(), v.end());
        int i = 0;
        for (char &c : s) {
            if (c == ' ') {
                c = v[i];
                i++;
            }
        }

        return s;
    }
};