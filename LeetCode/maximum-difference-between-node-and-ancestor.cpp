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

#define f first
#define s second
typedef pair<TreeNode*, pair<int, int>> p;

int maxAncestorDiff(TreeNode* root) {
    int ret = 0;
    queue<p> q; q.push({root, {root->val, root->val}});
    while (!q.empty()) {
        p u = q.front(); q.pop();
        ret = max(ret, max(abs(u.f->val - u.s.f), abs(u.f->val - u.s.s)));
        if (u.f->left) {
            p tmp = {u.f->left, {INT_MAX, INT_MIN}};
            tmp.s.f = min(u.s.f, u.f->val);
            tmp.s.s = max(u.s.s, u.f->val);
            q.push(tmp);
        }
        if (u.f->right) {
            p tmp = {u.f->right, {INT_MAX, INT_MIN}};
            tmp.s.f = min(u.s.f, u.f->val);
            tmp.s.s = max(u.s.s, u.f->val);
            q.push(tmp);
        }
    }

    return ret.f;
}

int main() {

    return 0;
}