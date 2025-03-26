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
    static const ll M = 1e9+7;
    static const ll B = 5;
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        for (int i = n-1; i >= 1; i--) {
            if (nums[i] > nums[i-1]) {nums[i] = 3;}
            else if (nums[i] == nums[i-1]) {nums[i] = 2;}
            else {nums[i] = 1;}
        }
        nums[0] = 0;
        for (int i = 0; i < m; i++) {
            pattern[i] += 2;
        }
        
        ll powB[n]; powB[0] = 1;
        for (int i = 1; i < n; i++) {powB[i] = (powB[i-1]*B)%M;}
        
        vector<ll> hashed(n, 0); hashed[0] = nums[0];
        for (int i = 1; i < n; i++) {
            hashed[i] = (hashed[i-1]*B+nums[i])%M;
        }
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans*B+pattern[i])%M;
        }
        
        int ret = 0;
        for (int i = 1; i < n-m+1; i++) {
            ll tmp = (hashed[i+m-1]%M-(hashed[i-1]*powB[m])%M+M)%M;
            ret += (tmp == ans);
        }
        
        return ret;
    }
};

int main() {

    return 0;
}