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

int n;
priority_queue<int, vector<int>, greater<int>> pq;

KthLargest(int k, vector<int>& nums) {
    n = k;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < k && i < nums.size(); i++) {pq.push(nums[nums.size()-i-1]);}
}

int add(int val) {
    if (pq.size() < n) {pq.push(val);}
    else if (val > pq.top()) {
        pq.pop();
        pq.push(val);
    }
    
    return pq.top();
}

int main() {

    return 0;
}