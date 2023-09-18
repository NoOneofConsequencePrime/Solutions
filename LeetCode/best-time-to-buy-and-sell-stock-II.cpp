#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int maxProfit(vector<int>& prices) {
    int mi = prices[0], ret = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < prices[i-1]) {
            ret += max(prices[i-1]-mi, 0);
            mi = prices[i];
        }
    }
    if (prices.size() > 1 && prices[prices.size()-1] >= prices[prices.size()-2]) ret += prices[prices.size()-1]-mi;

    return ret;
}

int main() {
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v);

    return 0;
}