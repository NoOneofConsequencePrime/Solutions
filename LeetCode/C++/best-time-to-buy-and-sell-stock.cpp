#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ret = 0;
    int mi = prices[0];
    for (int& x : prices) {
        mi = min(mi, x);
        ret = max(ret, x-mi);
    }

    return ret;
}

int main() {
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v);

    return 0;
}