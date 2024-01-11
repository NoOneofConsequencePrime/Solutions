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
typedef pair<int, pair<int, int>> p;

p getMaxDiff(TreeNode* root) {
    if (!root->left && !root->right) return {0, {root->val, root->val}};

    p ret = {0, {INT_MAX, INT_MIN}};
    if (root->left) {
        p tmp = getMaxDiff(root->left);
        ret.f = max(ret.f, max(tmp.f, abs(root->val - root->left->val)));
        ret.s.f = min(ret.s.f, min(tmp.s.f, root->left->val));
        ret.s.s = max(ret.s.s, max(tmp.s.s, root->left->val));
    }
    if (root->right) {
        p tmp = getMaxDiff(root->right);
        ret.f = max(ret.f, max(tmp.f, abs(root->val - root->right->val)));
        ret.s.f = min(ret.s.f, min(tmp.s.f, root->right->val));
        ret.s.s = max(ret.s.s, max(tmp.s.s, root->right->val));
    }

    ret.f = max(ret.f, max(abs(root->val - ret.s.f), abs(root->val - ret.s.s)));

    return ret;
}

int maxAncestorDiff(TreeNode* root) {
    p maxDiff = getMaxDiff(root);

    return maxDiff.f;
}

int main() {

    return 0;
}