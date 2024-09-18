class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int x : nums) {
            if (x == 0) {
                v.push_back("0");
                continue;
            }
            string tmp = "";
            while (x) {
                tmp += ('0'+(x%10));
                x /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), cmp);
        string ret = "";
        for (string &str : v) {
            ret += str;
        }

        int nonZero = ret.length()-1;
        for (int i = 0; i < ret.length(); i++) {
            if (ret[i] != '0') {
                nonZero = i;
                break;
            }
        }

        return ret.substr(nonZero, ret.length()-nonZero);
    }

    static bool cmp(string &a, string &b) {
        string tmpa = a+b, tmpb = b+a;
        return tmpb < tmpa;
    }
};