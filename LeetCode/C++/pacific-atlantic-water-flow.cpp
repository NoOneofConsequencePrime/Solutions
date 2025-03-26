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

int mx[4] = {1,-1,0,0}, my[4] = {0,0,1,-1};

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vst, queue<pii> &q, int b) {
    int n = grid.size(), m = grid[0].size();
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (vst[x][y] > b) {continue;}
        vst[x][y] += b+1;
        for (int i = 0; i < 4; i++) {
            int dx = x+mx[i], dy = y+my[i];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] >= grid[x][y]) {
                q.push({dx, dy});
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> ret, vst(n, vector<int>(m, 0));
    queue<pii> q;
    for (int i = 0; i < n; i++) {q.push({i, 0});}
    for (int i = 1; i < m; i++) {q.push({0, i});}
    bfs(heights, vst, q, 0);
    for (int i = 0; i < n; i++) {q.push({i, m-1});}
    for (int i = 0; i < m-1; i++) {q.push({n-1, i});}
    bfs(heights, vst, q, 1);
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vst[i][j] == 3) {ret.push_back({i, j});}
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> grid = {
        {10, 10, 10},
        {10, 1, 10},
        {10, 10, 10}
    };
    vector<vector<int>> ans = pacificAtlantic(grid);
    for (auto& v : ans) {
        printf("(%d, %d)\n", v[0], v[1]);
    }

    return 0;
}