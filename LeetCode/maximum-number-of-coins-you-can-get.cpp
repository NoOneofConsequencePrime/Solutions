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
using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end(), greater<int>());
    int ret = 0, n = piles.size();
    for (int i = 0; i < n/3; i++) ret += piles[i*2+1];

    return ret;
}

int main() {
    vector<int> v = {2,4,1,2,7,8};
    cout << maxCoins(v);

    return 0;
}