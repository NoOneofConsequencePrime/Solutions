class Solution {
    public:
        int diagonalSum(vector<vector<int>>& mat) {
            int sum = 0, n = mat.size();
            for (int i = 0, j = 0; i < n; i++, j++) {
                sum += mat[i][j] + mat[n-i-1][j];
                if (n-i-1 == i) {sum -= mat[i][j];}
            }
    
            return sum;
        }
    };