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
    long long flowerGame(int n, int m) {
        ll ret = 0;
        if (n > m) {swap(n, m);}
        for (int i = 1; i <= n; i++) {
            if (i%2 == 0) {
                ret += (m+1)/2;
            } else {
                ret += m/2;
            }
        }
        
        return ret;
    }
};

int main() {

    return 0;
}