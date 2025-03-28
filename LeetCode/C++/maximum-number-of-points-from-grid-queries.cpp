typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
private:
    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int MM = *max_element(queries.begin(), queries.end())+5;
        vector<int> psa(MM, 0);
        int m = grid.size(), n = grid[0].size();
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({grid[0][0], {0, 0}});
        int ma = grid[0][0];
        while (!pq.empty()) {
            ppi u = pq.top(); pq.pop();
            if (grid[u.s.f][u.s.s] < 0) {continue;}
            if (u.f <= ma) {
                if (ma+1 < MM) psa[ma+1]++;
            } else {
                ma = u.f;
                if (ma+1 < MM) psa[ma+1]++;
            }
            grid[u.s.f][u.s.s] = -1;

            for (int i = 0; i < 4; i++) {
                pii v = {u.s.f+mx[i], u.s.s+my[i]};
                if (v.f >= 0 && v.f < m && v.s >= 0 && v.s < n) {
                    pq.push({grid[v.f][v.s], v});
                }
            }
        }

        for (int i = 1; i < MM; i++) {
            psa[i] += psa[i-1];
        }

        vector<int> ret;
        for (auto x : queries) {
            ret.push_back(psa[x]);
        }

        return ret;
    }
};