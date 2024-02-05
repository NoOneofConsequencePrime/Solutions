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
    int idx[28];
public:
    int firstUniqChar(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int ret = INT_MAX;
        memset(idx, 0x3f, sizeof(idx));
        for (int i = 0; i < s.length(); i++) {
            if (idx[s[i]-'a'] > 1e6) {idx[s[i]-'a'] = i;}
            else {idx[s[i]-'a'] = 5e5;}
        }
        for (int i = 0; i < 26; i++) {
            ret = min(ret, idx[i]);
        }

        return (ret > 2e5)? -1 : ret;
    }
};

int main() {

    return 0;
}