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
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<ll, int> mp;
        for (int x : nums) {mp[x]++;}
        
        int ret = 0;
        for (int x : nums) {
            ll tmp = x;
            for (int i = 1; mp[tmp] >= 1; i++) {
                ret = max(ret, i);
                if (mp[tmp] == 1) {break;}
                mp[tmp] -= 2;
                tmp *= tmp;
            }
        }
        
        return ret*2-1;
    }
};

int main() {

    return 0;
}