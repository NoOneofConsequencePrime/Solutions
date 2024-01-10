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
unordered_map<TreeNode*, TreeNode*> pa;
int vst[MM];

int amountOfTime(TreeNode* root, int start) {
    stack<TreeNode*> stk; stk.push(root);
    TreeNode* str = NULL;
    while (!stk.empty()) {
        TreeNode* u = stk.top(); stk.pop();
        if (!u) {continue;}
        if (u->val == start) {str = u;}
        if (u->left) {
            pa[u->left] = u;
            stk.push(u->left);
        }
        if (u->right) {
            pa[u->right] = u;
            stk.push(u->right);
        }
    }

    memset(vst, -0x3f, sizeof(vst));
    int ret = 0;
    queue<TreeNode*> q; q.push(str); vst[start] = 0;
    while (!q.empty()) {
        TreeNode* u = q.front(); q.pop();
        if (!u) continue;
        ret = max(ret, vst[u->val]);

        if (u->left && vst[u->left->val] < 0) {
            vst[u->left->val] = vst[u->val]+1;
            q.push(u->left);
        }
        if (u->right && vst[u->right->val] < 0) {
            vst[u->right->val] = vst[u->val]+1;
            q.push(u->right);
        }
        if (pa.count(u) != 0 && vst[pa[u]->val] < 0) {
            vst[pa[u]->val] = vst[u->val]+1;
            q.push(pa[u]);
        }
    }

    return ret;
}

int main() {

    return 0;
}