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
    int ret = 0;
    while (n) {
        n &= (n-1);
        ret++;
    }

    return ret;
}

int main() {
    cout << hammingWeight()

    return 0;
}