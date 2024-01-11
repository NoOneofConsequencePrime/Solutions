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

int dfs(TreeNode* root, int mx, int mi) {
    if (!root) {return mx-mi;}

    mx = max(root->val, mx); mi = min(root->val, mi);

    return max(dfs(root->left, mx, mi), dfs(root->right, mx, mi));
}

int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
}

int main() {

    return 0;
}