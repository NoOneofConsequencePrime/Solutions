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

bool isPalindrome(int x) {
    string tmp = to_string(x);
    int len = tmp.length();
    for (int i = 0; i < len/2; i++) {
        if (tmp[i] != tmp[len-i-1]) return false;
    }

    return true;
}

int main() {
    cout << isPalindrome(-121);

    return 0;
}