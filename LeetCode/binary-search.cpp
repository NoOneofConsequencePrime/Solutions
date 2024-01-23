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

int search(vector<int>& nums, int target) {
    int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    if (lb >= nums.size() || nums[lb] != target) {return -1;}
    return lb;
}

int main() {
    vector<int> v = {-1,0,3,5,9,12};
    cout << search(v, 9);

    return 0;
}