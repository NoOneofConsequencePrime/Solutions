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

const int MM = 1e5+2;
bitset<2*MM> bst;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    for (auto &v : intervals) {
        for (int i = v[0]*2; i <= v[1]*2; i++) {bst[i] = 1;}
    }
    for (int i = newInterval[0]*2; i <= newInterval[1]*2; i++) {bst[i] = 1;}

    vector<vector<int>> ret;
    vector<int> tmp;
    for (int i = 0; i <= 2e5; i++) {
        if (bst[i]) {
            if (tmp.empty()) {tmp.push_back(i/2);}
            if (!bst[i+1]) {
                tmp.push_back(i/2);
                ret.push_back(tmp);
                tmp.clear();
            }
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> v = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> rg = {4,8};
    vector<vector<int>> ans = insert(v, rg);
    for (auto &vec : ans) {
        printf("%d - %d\n", vec[0], vec[1]);
    }

    return 0;
}