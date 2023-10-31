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

vector<int> findArray(vector<int>& pref) {
    vector<int> ret(pref.size());
    for (int i = pref.size()-1; i > 0; i--) ret[i] = pref[i]^pref[i-1];
    ret[0] = pref[0];

    return ret;
}

int main() {
    vector<int> v = {5,2,0,3,1};
    vector<int> ans = findArray(v);
    for (int x : ans) cout << x << " ";

    return 0;
}