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
    int findJudge(int n, vector<vector<int>>& trust) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<bool> a(n+1, true);
        vector<int> b(n+1, 0);
        for (auto &v : trust) {
            a[v[0]] = false;
            b[v[1]]++;
        }

        int tmp1 = 0, tmp2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                if (tmp1 != 0) {return -1;}
                else {tmp1 = i;}
            }
            if (b[i] == n-1) {
                if (tmp2 != 0) {return -1;}
                else {tmp2 = i;}
            }
        }

        if (tmp1 != tmp2) {return -1;}
        return tmp1;
    }
};

int main() {

    return 0;
}