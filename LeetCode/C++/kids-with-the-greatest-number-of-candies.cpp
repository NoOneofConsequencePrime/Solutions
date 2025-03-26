#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ret;
    int mx = -1;
    for (auto& x : candies) mx = max(mx, x);
    for (auto& x : candies) ret.push_back(x+extraCandies >= mx);

    return ret;
}

int main() {
    vector<int> v = {2,3,5,1,3};
    vector<bool> ans = kidsWithCandies(v, 3);
    for (auto x : ans) cout << x << " ";

    return 0;
}