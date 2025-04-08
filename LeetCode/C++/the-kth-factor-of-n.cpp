class Solution {
    public:
        int kthFactor(int n, int k) {
            int rt = sqrt(n);
            vector<int> a, b;
            for (int i = 1; i <= rt; i++) {
                if (n%i == 0) {
                    a.push_back(i);
                    b.push_back(n/i);
                }
            }
            reverse(b.begin(), b.end());
            for (auto x : b) {
                if (a.back() < x) {a.push_back(x);}
            }
    
            return k <= a.size()? a[k-1] : -1;
        }
    };