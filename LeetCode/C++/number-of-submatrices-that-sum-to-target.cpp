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

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> psa(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psa[i][j] = matrix[i-1][j-1];
            psa[i][j] += psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int lenV = 1; lenV+i-1 <= n; lenV++) {
                for (int lenH = 1; lenH+j-1 <= m; lenH++) {
                    printf("(%d, %d): %d - %d\n", i, j, lenV, lenH);
                    int sum = psa[i+lenV-1][j+lenH-1]-psa[i-1][j+lenH-1]-psa[i+lenV-1][j-1]+psa[i-1][j-1];
                    if (sum == target) {ret++;}
                }
            }
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> grid = {
        {0,1,0},
        {1,1,1},
        {0,1,0}
    };
    cout << numSubmatrixSumTarget(grid, 0);

    return 0;
}