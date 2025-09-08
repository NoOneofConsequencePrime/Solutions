class Solution {
private:
    bool chk(int n) {
        while (n) {
            if (n%10 == 0) {return false;}
            n /= 10;
        }

        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ret;
        for (int i = 1; i <= n/2; i++) {
            if (chk(i) && chk(n-i)) {
                ret.push_back(i);
                ret.push_back(n-i);

                break;
            }
        }

        return ret;
    }
};