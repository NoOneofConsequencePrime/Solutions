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

const int MM = 1e4+2;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum%2) {return false;}
    sum /= 2;
    bitset<MM> bst(1);

    for (int num : nums) {
        bst |= bst<<num;
        if (bst[sum]) {return true;}
    }

    return false;
}

int main() {
    vector<int> v = {1,5,11,5};
    cout << canPartition(v);

    return 0;
}