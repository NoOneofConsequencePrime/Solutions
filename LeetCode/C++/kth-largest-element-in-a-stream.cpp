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
    this->k = k;
    for (int x : nums) {pq.push(x);}
    while (pq.size() > k) {pq.pop();}
}

int add(int val) {
    pq.push(val);
    if (pq.size() > k) {pq.pop();}
    
    return pq.top();
}

int main() {

    return 0;
}