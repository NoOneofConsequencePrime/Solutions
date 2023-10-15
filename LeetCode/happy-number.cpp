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

bool isHappy(int n) {
    unordered_set<int> st;
    while (true) {
        int m = 0;
        while (n != 0) {
            m += (n%10) * (n%10);
            n /= 10;
        }
        if (st.count(m) != 0) return false;
        if (m == 1) break;
        st.insert(m);
        n = m;
    }

    return true;
}

int main() {
    cout << isHappy(19);

    return 0;
}