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

int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int x : nums) ret ^= x;

    return ret;
}

int main() {
    vector<int> v = {4,1,2,1,2};
    cout << singleNumber(v);

    return 0;
}