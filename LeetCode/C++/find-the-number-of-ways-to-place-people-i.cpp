class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {continue;}
                int a = points[i][0], b = points[i][1];
                int x = points[j][0], y = points[j][1];
                
                if (a > x || b < y) {continue;}
                if (n == 2) {return 1;}
                bool isValid = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {continue;}
                    int c = points[k][0], d = points[k][1];
                    if ((a <= c && c <= x) && (y <= d && d <= b)) {
                        isValid = false;
                    }
                }

                ret += isValid;
            }
        }

        return ret;
    }
};