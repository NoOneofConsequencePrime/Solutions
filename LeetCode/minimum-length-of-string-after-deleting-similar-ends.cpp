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
    int minimumLength(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = s.length();
        int l = 0, r = n-1;
        for (; l < r; l++, r--) {
            if (l == r) {break;}
            else if (l > r) {l--; r++; break;}
            if (s[l] != s[r]) {break;}

            while (l < r-1) {
                if (s[l+1] == s[r]) {l++;}
                else {break;}
            }
            while (r > l+1) {
                if (s[r-1] == s[l]) {r--;}
                else {break;}
            }
        }

        return r-l+1;
    }
};

int main() {

    return 0;
}