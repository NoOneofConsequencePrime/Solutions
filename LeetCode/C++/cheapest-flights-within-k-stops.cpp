#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<pii>> edge(n, vector<pii>());
        for (auto &v : flights) {
            edge[v[0]].push_back({v[1], v[2]});
        }

        vector<int> vis(n, INT_MAX); vis[src] = 0;
        int ret = INT_MAX;
        queue<ppi> q; q.push({src, {0, -1}});
        while (!q.empty()) {
            ppi u = q.front(); q.pop();
            if (u.f == dst) {
                ret = min(ret, u.s.f);
                continue;
            } else if (u.s.s >= k) {continue;}

            for (pii v : edge[u.f]) {
                ppi d = {v.f, {u.s.f+v.s, u.s.s+1}};
                if (d.s.f < vis[d.f]) {
                    vis[d.f] = d.s.f;
                    q.push(d);
                }
            }
        }

        return (ret != INT_MAX)? ret : -1;
    }
};

int main() {

    return 0;
}