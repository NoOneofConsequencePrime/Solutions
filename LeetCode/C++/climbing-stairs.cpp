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

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; i++) {
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    cout << climbStairs(3);

    return 0;
}