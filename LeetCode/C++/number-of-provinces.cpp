class Solution {
    private:
        static const int MM = 202;
        int pa[MM];
        int fd(int u) {
            if (pa[u] != u) pa[u] = fd(pa[u]);
            return pa[u];
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            for (int i = 0; i < n; i++) {pa[i] = i;}
            
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    if (isConnected[i][j]) {
                        if (fd(i) != fd(j)) {pa[fd(i)] = fd(j);}
                    }
                }
            }
    
            vector<bool> chk(n, false);
            int ret = 0;
            for (int i = 0; i < n; i++) {
                if (!chk[fd(i)]) {
                    chk[fd(i)] = true;
                    ret++;
                }
            }
    
            return ret;
        }
    };