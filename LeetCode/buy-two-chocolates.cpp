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

int buyChoco(vector<int>& prices, int money) {
    sort(prices.begin(), prices.end());
    int sum = prices[0]+prices[1];
    return (money < sum)? money : money-sum;
}

int main() {
    vector<int> v = {3,2,3};
    cout << buyChoco(v, 3);

    return 0;
}