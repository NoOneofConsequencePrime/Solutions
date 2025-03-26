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

int characterReplacement(string s, int k) {
    int ret = 0, n = s.length();
    for (char c = 'A'; c <= 'Z'; c++) {
        int tmpCnt = 0;
        for (int i = 0, j = 0; j < n; j++) {
            if (s[j] != c) {tmpCnt++;}
            while (i<=j && tmpCnt>k) {
                tmpCnt -= (s[i] != c);
                i++;
            }
            ret = max(ret, j-i+1);
        }
    }

    return ret;
}

int main() {
    cout << characterReplacement("AABABBA", 1);

    return 0;
}