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
private:
    map<int, vector<pii>> mp;
    vector<bool> chk, vis;
    vector<vector<int>> adj;

    bool dfs(int u) {
        if (chk[u]) {return true;}
        if (vis[u]) {return chk[u];}
        vis[u] = true;

        bool ret = false;
        for (int v : adj[u]) {
            if (dfs(v)) {ret = true;}
        }
        
        return chk[u] = ret;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        adj = vector<vector<int>>(n, vector<int>());
        chk = vector<bool>(n, false); chk[0] = chk[firstPerson] = true;
        vis = vector<bool>(n, false);
        for (auto &v : meetings) {
            mp[v[2]].push_back({v[0], v[1]});
        }

        for (auto &[a, v] : mp) {
            vector<int> tmp;
            for (pii p : v) {
                adj[p.f].push_back(p.s);
                adj[p.s].push_back(p.f);
                tmp.push_back(p.f); tmp.push_back(p.s);
            }
            for (int x : tmp) {
                fill(vis.begin(), vis.end(), false);
                dfs(x);
            }
            for (int x : tmp) {adj[x].clear();}
        }

        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (chk[i]) {ret.push_back(i);}
        }
        return ret;
    }
};

int main() {
    Solution ans;
    vector<vector<int>> v = {{3,1,3},{1,2,2},{0,3,3}};
    vector<int> ret = ans.findAllPeople(4, v, 3);
    for (int x : ret) {cout << x << " ";}

    return 0;
}