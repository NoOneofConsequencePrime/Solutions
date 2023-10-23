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

bool isPowerOfFour(int n) {
    return (__builtin_ctz(n)%2 == 0 && __builtin_clz(n)+__builtin_ctz(n) == 31);
}

int main() {
    cout << isPowerOfFour(64);

    return 0;
}