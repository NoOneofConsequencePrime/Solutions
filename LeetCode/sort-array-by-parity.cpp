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

vector<int> sortArrayByParity(vector<int>& nums) {
    deque<int> dq;
    for (int& x : nums) {
        if (x%2) dq.push_back(x);
        else dq.push_front(x);
    }

    vector<int> ret;
    while (!dq.empty()) {
        ret.push_back(dq.front());
        dq.pop_front();
    }

    return ret;
}

int main() {
    vector<int> v = {3,1,2,4};
    vector<int> ans = sortArrayByParity(v);
    for (int&x : ans) cout << x << " ";

    return 0;
}