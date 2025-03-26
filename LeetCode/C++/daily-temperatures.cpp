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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = temperatures.size();
        vector<int> ret(n, 0);
        stack<int> stk;
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()]<=temperatures[i]) {stk.pop();}
            if (!stk.empty()) {
                ret[i] = stk.top()-i;
            }
            stk.push(i);
        }

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = {73,74,75,71,69,72,76,73};
    vector<int> ret = ans.dailyTemperatures(v);
    for (int x : ret) {cout << x << " ";}

    return 0;
}