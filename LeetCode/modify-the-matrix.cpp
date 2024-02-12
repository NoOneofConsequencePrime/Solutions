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
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {ret[i][j] = matrix[i][j];}
        }
        
        for (int j = 0; j < m; j++) {
            int ma = INT_MIN;
            for (int i = 0; i < n; i++) {
                ma = max(ma, ret[i][j]);
            }
            for (int i = 0; i < n; i++) {
                if (ret[i][j] == -1) {ret[i][j] = ma;}
            }
        }
        
        return ret;
    }
};

int main() {

    return 0;
}