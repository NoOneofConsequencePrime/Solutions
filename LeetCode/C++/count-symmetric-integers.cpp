class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ret = 0;
            for (int i = low; i <= high; i++) {
                if (i < 10 || (i >= 100 && i < 1000) || i >= 10000) {continue;}
                if (i < 100) {
                    if (i%10 == i/10) {ret++;}
                } else if (i >= 1000) {
                    if (i%10+i/10%10 == i/100%10+i/1000) {ret++;}
                }
            }
    
            return ret;
        }
    };