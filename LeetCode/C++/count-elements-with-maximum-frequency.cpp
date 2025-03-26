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
    int maxFrequencyElements(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int cnt[101] = {};
        for (int x : nums) {cnt[x]++;}

        int ret = 0, mx = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] > 0) {
                if (cnt[i] > mx) {
                    mx = cnt[i];
                    ret = cnt[i];
                } else if (cnt[i] == mx) {
                    ret += cnt[i];
                }
            }
        }

        return ret;
    }
};

int main() {

    return 0;
}