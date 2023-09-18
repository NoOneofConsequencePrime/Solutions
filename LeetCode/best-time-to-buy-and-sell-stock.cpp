#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ret = 0;
    stack<int> stk;
    int mi = 0;
    for (int& x : prices) {
        while (stk.size() > 0 && stk.top() > x) {
            ret = max(ret, stk.top()-mi);
            stk.pop();
        }
        if (stk.size() == 0) mi = x;
        stk.push(x);
    }
    ret = max(ret, stk.top()-mi);

    return ret;
}

int main() {
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v);

    return 0;
}