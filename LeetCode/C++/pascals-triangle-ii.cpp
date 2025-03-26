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

vector<int> getRow(int rowIndex) {
    vector<int> ret(rowIndex+1, 1);
    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j > 0; j--) ret[j] += ret[j-1];
    }

    return ret;
}

int main() {
    vector<int> ans = getRow(3);
    for (auto& x : ans) cout << x << " ";

    return 0;
}