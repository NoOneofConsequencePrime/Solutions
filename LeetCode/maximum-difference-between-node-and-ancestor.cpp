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

    int tmpMx = max(root->val, mx), tmpMi = min(root->val, mi);

    return max(dfs(root->left, tmpMx, tmpMi), dfs(root->right, tmpMx, tmpMi));
}

int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
}

int main() {

    return 0;
}