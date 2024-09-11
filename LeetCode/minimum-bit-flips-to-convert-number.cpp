class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = 0;
        while (start || goal) {
            if ((start&1) != (goal&1)) {ret++;}
            start >>= 1; goal >>= 1;
        }

        return ret;
    }
};