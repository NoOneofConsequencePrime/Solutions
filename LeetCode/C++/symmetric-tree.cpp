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

bool isSymmetric(TreeNode* root) {
    queue<pair<TreeNode*, TreeNode*>> q; q.push({root->left, root->right});
    bool ret = true;
    while (!q.empty()) {
        auto [nodeA, nodeB] = q.front(); q.pop();

        if (!nodeA && !nodeB) continue;
        if (!nodeA != !nodeB || nodeA->val != nodeB->val) return false;
        q.push({nodeA->left, nodeB->right}); q.push({nodeA->right, nodeB->left});
    }

    return ret;
}

int main() {

    return 0;
}