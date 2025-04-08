class Solution {
    public:
        int kthFactor(int n, int k) {
            for (int i = 1, j = 0; i <= n; i++) {
                if (n%i == 0) {
                    j++;
                    if (j == k) {return i;}
                }
            }
    
            return -1;
        }
    };