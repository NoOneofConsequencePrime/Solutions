#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int jump(vector<int>& nums) {
    int dis[nums.size()]; fill(dis, dis+nums.size(), -1);
    queue<int> q;
    dis[0] = 0; q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == nums.size()-1) return dis[u];
        for (int v = u+1; v <= u+nums[u] && v < nums.size(); v++) {
            if (dis[v] == -1) {
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }

    return -1;
}

int main() {
    vector<int> v = {2,3,0,1,4};
    cout << jump(v);

    return 0;
}