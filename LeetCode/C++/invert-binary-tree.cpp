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

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* tmpNode = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmpNode);

    return root;
}

int main() {

    return 0;
}