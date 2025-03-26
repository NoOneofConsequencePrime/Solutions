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

int findContentChildren(vector<int>& g, vector<int>& s) {
    int ret = 0;
    sort(g.begin(), g.end()); sort(s.begin(), s.end());
    for (int i = s.size()-1, j = g.size()-1; i >= 0 && j >= 0; i--, j--) {
        while (j >= 0 && g[j] > s[i]) {
            j--;
        }
        if (j >= 0) ret++;
    }

    return ret;
}

int main() {
    vector<int> a = {1,2}, b = {1,2,3};
    cout << findContentChildren(a, b);

    return 0;
}