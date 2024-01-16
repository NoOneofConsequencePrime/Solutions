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

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    return nums[nums.size()-k];
}

int main() {
    vector<int> v = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(v, 4);

    return 0;
}