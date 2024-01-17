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

const int MM = 302;
bitset<MM> vst[MM];
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};

void ffill(vector<vector<char>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    vst[x][y] = 1;
    queue<pii> q; q.push({x, y});
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pii v = {u.f+mx[i], u.s+my[i]};
            if (v.f>=0 && v.f<n && v.s>=0 && v.s<m && grid[v.f][v.s]=='1' && !vst[v.f][v.s]) {
                vst[v.f][v.s] = 1;
                q.push(v);
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='1' && !vst[i][j]) {
                ret++;
                ffill(grid, i, j);
            }
        }
    }
    
    return ret;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}};
    cout << numIslands(grid);

    return 0;
}