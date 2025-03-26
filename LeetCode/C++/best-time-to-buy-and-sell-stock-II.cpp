#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); i++) {
        ret += max(0, prices[i]-prices[i-1]);
    }

    return ret;
}

int main() {
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v);

    return 0;
}