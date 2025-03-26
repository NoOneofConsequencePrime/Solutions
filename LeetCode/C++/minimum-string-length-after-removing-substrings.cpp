class Solution {
public:
    int minLength(string s) {
        return ridOf(s).length();
    }

    string ridOf(string &str) {
        size_t ab = str.find("AB"), cd = str.find("CD");
        string ret = str;
        if (ab != string::npos) {
            ret = str.substr(0, ab) + str.substr(ab+2);
        } else if (cd != string::npos) {
            ret = str.substr(0, cd) + str.substr(cd+2);
        }

        if (ret == str) {return ret;}
        else {return ridOf(ret);}
    }
};