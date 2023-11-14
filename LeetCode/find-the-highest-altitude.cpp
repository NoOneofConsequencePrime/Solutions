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

int largestAltitude(vector<int>& gain) {
    int ret = 0, cur = 0;
    for (auto& x : gain) {
        cur += x;
        ret = max(ret, cur);
    }

    return ret;
}

int main() {
    vector<int> v = {-5,1,5,0,-7};
    cout << largestAltitude(v);

    return 0;
}