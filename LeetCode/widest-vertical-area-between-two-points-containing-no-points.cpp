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

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    vector<int> v;
    for (auto tmp : points) v.push_back(tmp[0]);
    sort(v.begin(), v.end());

    int ret = 0;
    for (int i = 1; i < v.size(); i++) ret = max(ret, v[i]-v[i-1]);

    return ret;
}

int main() {
    vector<vector<int>> v = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    cout << maxWidthOfVerticalArea(v);

    return 0;
}