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

const int M = 1e9+7;
vector<int> primes;
unordered_map<int, int> dp;

bool chkPrime(int num) {
    for (int x : primes) {
        if (num%x == 0) {return false;}
    }

    return true;
}

void genPrimes(int n) {
    for (int i = 2; primes.size() < n; i++) {
        if (chkPrime(i)) {primes.push_back(i);}
    }
}

int qPow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if ((e&1) == 1) {ret = (ret*b)%M;}
        e >>= 1;
        b = (b*b)%M;
    }

    return ret;
}

int hsh(vector<int>& v) {
    ll ret = 0;
    for (int i = 0; i < v.size(); i++) {
        ret = (ret+qPow(primes[i], v[i]))%M;
    }

    return ret;
}

int fun(vector<int>& nums) {
    int n = nums.size(), curHsh = hsh(nums);
    if (n == 1) {return nums[0];}
    if (dp.count(curHsh) != 0) {return dp[curHsh];}

    for (int i = 0; i < n; i++) {
        int tmpV = nums[i]*((i>=1)? nums[i-1]:1)*((i<=n-2)? nums[i+1]:1);
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (j != i) {v.push_back(nums[j]);}
        }
        dp[curHsh] = max(dp[curHsh], tmpV+fun(v));
    }

    return dp[curHsh];
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    genPrimes(n);

    return fun(nums);
}

int main() {
    vector<int> v = {3,1,5,8};
    cout << maxCoins(v);

    return 0;
}