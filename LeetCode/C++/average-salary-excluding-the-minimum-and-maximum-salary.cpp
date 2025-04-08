class Solution {
    public:
        double average(vector<int>& salary) {
            double total = 0;
            int mi = INT_MAX, ma = INT_MIN;
            for (int x : salary) {
                total += x;
                mi = min(mi, x);
                ma = max(ma, x);
            }
            total -= (mi + ma);
            total /= (salary.size()-2);
    
            return total;
        }
    };