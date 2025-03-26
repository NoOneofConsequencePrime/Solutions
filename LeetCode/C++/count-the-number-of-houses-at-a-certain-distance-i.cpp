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
    static const int MM = 102;
    bitset<MM> vst;
public:
    vector<int> countOfPairs(int n, int x, int y) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> ret(n, 0);
        for (int i = 1; i <= n; i++) {
            vst.reset();
            queue<pii> q; q.push({i, 0}); vst[i] = 1;
            while (!q.empty()) {
                pii v = q.front(); q.pop();
                if (v.f > 1 && vst[v.f-1] == 0) {
                    vst[v.f-1] = 1;
                    q.push({v.f-1, v.s+1});
                    ret[v.s]++;
                }
                if (v.f < n && vst[v.f+1] == 0) {
                    vst[v.f+1] = 1;
                    q.push({v.f+1, v.s+1});
                    ret[v.s]++;
                }
                if (v.f == x && vst[y] == 0) {
                    vst[y] = 1;
                    q.push({y, v.s+1});
                    ret[v.s]++;
                }
                if (v.f == y && vst[x] == 0) {
                    vst[x] = 1;
                    q.push({x, v.s+1});
                    ret[v.s]++;
                }
             }
        }
        
        return ret;
    }
};

int main() {

    return 0;
}