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
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        for (int i = n-1; i >= 1; i--) {
            if (nums[i] > nums[i-1]) {nums[i] = 1;}
            else if (nums[i] == nums[i-1]) {nums[i] = 0;}
            else {nums[i] = -1;}
        }
        
        int ret = 0;
        for (int i = 1; i < n-m+1; i++) {
            bool flag = true;
            for (int j = i; j < i+m; j++) {
                if (nums[j] != pattern[j-i]) {flag = false;}
            }
            ret += flag;
        }
        
        return ret;
    }
};

int main() {

    return 0;
}