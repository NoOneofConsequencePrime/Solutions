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
    if (rowIndex == 0) return {1};
    
    vector<int> tmp = getRow(rowIndex-1), ret;
    ret.push_back(1);
    for (int i = 1; i < tmp.size(); i++) {
        ret.push_back(tmp[i-1]+tmp[i]);
    }
    ret.push_back(1);

    return ret;
}

int main() {
    vector<int> ans = getRow(3);
    for (auto& x : ans) cout << x << " ";

    return 0;
}