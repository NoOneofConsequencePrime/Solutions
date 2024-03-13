class Solution {
private:
    int hshk(int n) {
        return n*(n+1)/2;
    }
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            if (hshk(i) == hshk(n)-hshk(i-1)) {return i;}
        }

        return -1;
    }
};