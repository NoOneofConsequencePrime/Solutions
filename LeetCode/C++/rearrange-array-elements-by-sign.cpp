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
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> a, b;
        for (int x : nums) {
            if (x > 0) {a.push_back(x);}
            else {b.push_back(x);}
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i%2 == 0) {nums[i] = a[i/2];}
            else {nums[i] = b[i/2];}
        }

        return nums;
    }
};

int main() {

    return 0;
}