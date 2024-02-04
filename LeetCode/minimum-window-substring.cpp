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
    static const int MM = 55;
    int cnt[MM] = {}, tmp[MM] = {};

    static int getIdx(char c) {
        if (c <= 'Z') {return c-'A';}
        else {return c-'a'+26;}
    }

    bool chk(int no) {
        for (int i = 0; i < MM; i++) {
            if (tmp[i] < cnt[i]) {return false;}
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = s.length();
        string ret = "";
        for (char c : t) {
            cnt[getIdx(c)]++;
        }

        for (int l = 0, r = 0; r < n; r++) {
            tmp[getIdx(s[r])]++;
            while (chk(--tmp[getIdx(s[l])]) && l < r) {
                l++;
            }
            tmp[getIdx(s[l])]++;
            if (chk(0)) {
                if (ret == "") {ret = s.substr(l, r-l+1);}
                else if (ret.length() > r-l+1) {ret = s.substr(l, r-l+1);}
            }
        }

        return ret;
    }
};

int main() {
    Solution ans;
    cout << ans.minWindow("ADOBECODEBANC", "ABC");

    return 0;
}