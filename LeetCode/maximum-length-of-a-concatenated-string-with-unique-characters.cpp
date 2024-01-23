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

int fun(vector<string>& arr, int mask, int n) {
    int len = arr.size();
    if (n >= len) {return __builtin_popcount(mask);}

    int ret = fun(arr, mask, n+1);
    for (char c : arr[n]) {
        int pos = c-'a';
        if (mask>>pos & 1) {return ret;}
        else {mask |= 1<<pos;}
    }

    return max(ret, fun(arr, mask, n+1));
}

int maxLength(vector<string>& arr) {
    return fun(arr, 0, 0);
}

int main() {
    vector<string> v = {"cha","r","act","ers"};
    cout << maxLength(v);

    return 0;
}