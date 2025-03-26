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

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {a[i] = matrix[0][i];}
    for (int i = 1; i < n; i++) {
        fill(b.begin(), b.end(), INT_MAX);
        for (int j = 0; j < n; j++) {
            b[j] = matrix[i][j]+a[j];
            if (j > 0) {b[j] = min(b[j], matrix[i][j]+a[j-1]);}
            if (j < n-1) {b[j] = min(b[j], matrix[i][j]+a[j+1]);}
        }
        swap(a, b);
    }

    int ret = INT_MAX;
    for (int i = 0; i < n; i++) {ret = min(ret, a[i]);}

    return ret;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,3},
        {6,5,4},
        {7,8,9}};
    cout << minFallingPathSum(grid);

    return 0;
}