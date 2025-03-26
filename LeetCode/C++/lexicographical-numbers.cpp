class Solution {
public:
    int m;
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        m = n;
        fun(0, ret);

        return ret;
    }

    void fun(int num, vector<int> &v) {
        for (int i = 0; i <= 9; i++) {
            int tmp = num*10+i;
            if (tmp == 0) {continue;}
            if (tmp > m) {break;}
            v.push_back(tmp);
            fun(tmp, v);
        }
    }
};