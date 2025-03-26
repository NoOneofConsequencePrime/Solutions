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
    int countKeyChanges(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int ret = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (tolower(s[i]) != tolower(s[i-1])) {ret++;}
        }
        
        return ret-1;
    }
};

int main() {

    return 0;
}