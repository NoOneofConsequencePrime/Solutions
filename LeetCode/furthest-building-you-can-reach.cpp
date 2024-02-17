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
    bool chk(vector<int>& v, int idx, int b, int l) {
        vector<int> tmp = {v.begin()+1, v.begin()+idx+1};
        sort(tmp.begin(), tmp.end());
        ll sum = 0;
        for (int i = tmp.size()-l-1; i >= 0; i--) {
            sum += tmp[i];
        }

        return sum <= b;
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = heights.size();
        for (int i = n-1; i >= 1; i--) {
            if (heights[i] > heights[i-1]) {heights[i] -= heights[i-1];}
            else {heights[i] = 0;}
        }
        int l = 1, r = heights.size()-1, ret = 0;
        while (l <= r) {
            int m = (l+r)/2;

            if (chk(heights, m, bricks, ladders)) {
                ret = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return ret;
    }
};

int main() {

    return 0;
}