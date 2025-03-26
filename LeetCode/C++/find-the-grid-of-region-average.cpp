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

typedef pair<int, int> pii;
#define f first
#define s second

class Solution {
public:
    int move[5] = {1, 0, -1, 0, 1};
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = image.size(), m = image[0].size();
        vector<vector<pii>> grid(n, vector<pii>(m, {0, 0}));
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                int mi = INT_MAX, ma = INT_MIN;
                bool flag = true;
                int sum = 0;
                for (int a = i; a < i+3; a++) {
                    for (int b = j; b < j+3; b++) {
                        for (int k = 0; k < 4; k++) {
                            int dx = a+move[k], dy = b+move[k+1];
                            if (dx<i || dx>=i+3 || dy<j || dy>=j+3) {continue;}
                            if (abs(image[dx][dy]-image[a][b]) > threshold) {
                                flag = false;
                            }
                        }
                        sum += image[a][b];
                    }
                }
                sum /= 9;
                if (flag) {
                    for (int a = i; a < i+3; a++) {
                        for (int b = j; b < j+3; b++) {
                            grid[a][b].f += sum;
                            grid[a][b].s++;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j].s == 0) {ret[i][j] = image[i][j];}
                else {
                    ret[i][j] = grid[i][j].f/grid[i][j].s;
                }
            }
        }
        
        return ret;
    }
};

int main() {

    return 0;
}