typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pii> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {v.push_back({i, j});}
            }
        }

        for (pii p : v) {
            for (int i = 0; i < m; i++) {
                matrix[i][p.s] = 0;
            }
            for (int j = 0; j < n; j++) {
                matrix[p.f][j] = 0;
            }
        }
    }
};