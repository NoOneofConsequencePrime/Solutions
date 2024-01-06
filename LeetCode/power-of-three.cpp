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
    if (n < 3) return n==1;
    else if (n%3 != 0) return false;

    return isPowerOfThree(n/3);
}

int main() {
    printf("%d %d %d %d\n", isPowerOfThree(27), isPowerOfThree(9), isPowerOfThree(3), isPowerOfThree(1));

    return 0;
}