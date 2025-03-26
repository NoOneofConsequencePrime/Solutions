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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool isPowerOfThree(int n) {
    return (n>0) && !(1162261467%n);
}

int main() {
    printf("%d %d %d %d\n", isPowerOfThree(27), isPowerOfThree(9), isPowerOfThree(3), isPowerOfThree(1));

    return 0;
}