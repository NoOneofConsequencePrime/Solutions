class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int a = 0, b = 0;
            for (int i = 2; i <= cost.size(); i++) {
                swap(a, b);
                b = min(a+cost[i-1], b+cost[i-2]);
            }
    
            return b;
        }
    };