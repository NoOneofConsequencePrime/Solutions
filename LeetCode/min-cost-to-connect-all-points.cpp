#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<pair<int, int>> adj[1002];

    // compute all edges
    for (int i = 0; i < points.size(); i++) {
        auto& a = points[i];
        for (int j = i+1; j < points.size(); j++) {
            auto& b = points[j];
            int dist = abs(a[0]-b[0])+abs(a[1]-b[1]);
            adj[i].push_back({dist, j});
            adj[j].push_back({dist, i});
        }
    }

    // prims
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    bool vis[1002]; fill(vis, vis+1002, false);
    int dis[1002]; memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0; q.push({dis[0], 0});
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& ve : adj[u]) {
            int vd = ve.first, v = ve.second;
            if (!vis[v] && vd < dis[v]) {
                dis[v] = vd;
                q.push({vd, v});
            }
        }
    }

    // sum length;
    int sum = 0;
    for (int i = 0; i < points.size(); i++) sum += dis[i];

    return sum;
}

int main() {
    vector<vector<int>> v = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << minCostConnectPoints(v);

    return 0;
}