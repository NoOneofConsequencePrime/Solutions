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

int calc(int n) {
    int ret = 0;
    while (n) {
        ret += (n%10)*(n%10);
        n /= 10;
    }

    return ret;
}

bool isHappy(int n) {
    int a = calc(n), b = calc(calc(n));
    while (a != b || a == 1) {
        a = calc(a); b = calc(calc(b));
        if (a == 1) return true;
    }

    return false;
}

int main() {
    cout << isHappy(19);

    return 0;
}