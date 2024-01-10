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

const int MM = 1e5+2;
vector<int> adj[MM];
bool vst[MM];

int amountOfTime(TreeNode* root, int start) {
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* u = q.front(); q.pop();
        if (u->left) {
            adj[u->left->val].push_back(u->val);
            adj[u->val].push_back(u->left->val);
            q.push(u->left);
        }
        if (u->right) {
            adj[u->right->val].push_back(u->val);
            adj[u->val].push_back(u->right->val);
            q.push(u->right);
        }
    }

    queue<pair<int, int>> nq; nq.push({start, 0}); vst[start] = true;
    int ret = 0;
    while (!nq.empty()) {
        pair<int, int> u = nq.front(); nq.pop();
        ret = max(ret, u.second);
        for (int x : adj[u.first]) {
            if (!vst[x]) {
                nq.push({x, u.second+1});
                vst[x] = true;
            }
        }
    }

    return ret;
}

int main() {

    return 0;
}