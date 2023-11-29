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

int hammingWeight(uint32_t n) {
    return __builtin_popcount(n);
}

int main() {
    cout << hammingWeight()

    return 0;
}