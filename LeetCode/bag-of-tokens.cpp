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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        if (tokens.size() == 0) {return 0;}
        sort(tokens.begin(), tokens.end());
        if (tokens[0] > power) {return 0;}
        int n = tokens.size(), ret = 1;
        for (int i = 1; i < n; i++) {
            tokens[i] += tokens[i-1];
            if (tokens[i] <= power) {ret = max(ret, i+1);}
        }
        for (int i = 0; i < n; i++) {
            int tmp = power+tokens[n-1]-2*tokens[i];
            if (tmp >= 0) {ret = max(ret, ((i+1)*2-n));}
            else {break;}
        }
        for (int i = 1; i < n-1; i++) {
            int tmp = power+tokens[n-1]-tokens[i]-tokens[i-1];
            if (tmp >= 0) {ret = max(ret, 2*i+1-n);}
            else {break;}
        }

        return ret;
    }
};

int main() {

    return 0;
}