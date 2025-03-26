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
    int m1, m2; m1 = m2 = 200;
    for (int x : prices) {
        if (x < m1) {
            m2 = m1;
            m1 = x;
        } else if (x < m2) m2 = x;
    }
    int sum = m1+m2;
    return (money < sum)? money : money-sum;
}

int main() {
    vector<int> v = {3,2,3};
    cout << buyChoco(v, 3);

    return 0;
}