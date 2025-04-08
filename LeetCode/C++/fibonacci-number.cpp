class Solution {
    private:
        int dp[35] = {};
    public:
        int fib(int n) {
            if (n <= 1) {return n;}
            if (dp[n] != 0) {return dp[n];}
    
            return dp[n] = fib(n-1) + fib(n-2);
        }
    };