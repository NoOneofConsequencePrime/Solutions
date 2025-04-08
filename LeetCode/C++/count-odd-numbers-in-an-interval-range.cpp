class Solution {
    public:
        int countOdds(int low, int high) {
            int rg = high-low+1;
            return (rg%2 == 0)? rg/2 : (low%2 == 1)? rg/2+1 : rg/2;
        }
    };