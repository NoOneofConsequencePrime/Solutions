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

bool isSame(TreeNode* nodeA, TreeNode* nodeB) {
    if (!nodeA != !nodeB) return false;
    if (!nodeA && !nodeB) return true;

    return (nodeA->val == nodeB->val) && isSame(nodeA->left, nodeB->right) && isSame(nodeA->right, nodeB->left);
}

bool isSymmetric(TreeNode* root) {
    return isSame(root->left, root->right);
}

int main() {

    return 0;
}