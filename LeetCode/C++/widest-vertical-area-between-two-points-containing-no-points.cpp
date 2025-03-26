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
    sort(points.begin(), points.end());

    int ret = 0;
    for (int i = 1; i < points.size(); i++) ret = max(ret, points[i][0]-points[i-1][0]);

    return ret;
}

int main() {
    vector<vector<int>> v = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    cout << maxWidthOfVerticalArea(v);

    return 0;
}