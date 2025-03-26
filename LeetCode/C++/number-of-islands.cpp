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

int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};

void ffill(vector<vector<char>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    grid[x][y] = '0';

    for (int i = 0; i < 4; i++) {
        pii v = {x+mx[i], y+my[i]};
        if (v.f>=0 && v.f<n && v.s>=0 && v.s<m && grid[v.f][v.s]=='1') {
            ffill(grid, v.f, v.s);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='1') {
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