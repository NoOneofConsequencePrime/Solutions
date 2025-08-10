class Solution {
private:
    bool chk(int (&arrA)[10], int (&arrB)[10]) {
        bool ret = true;
        for (int i = 0; i < 10; i++) {
            if (arrA[i] != arrB[i]) {return false;}
        }

        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        int arrA[10] = {};
        while (n) {
            arrA[n%10]++;
            n /= 10;
        }
        for (int i = 1; i <= 1e9; i*=2) {
            int arrB[10] = {};
            int j = i;
            while (j) {
                arrB[j%10]++;
                j /= 10;
            }
            if (chk(arrA, arrB)) {return true;}
        }

        return false;
    }
};