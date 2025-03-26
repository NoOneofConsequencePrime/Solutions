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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {return false;}

    bool ret = false;
    if (root->left) {ret |= hasPathSum(root->left, targetSum-root->val);}
    if (root->right) {ret |= hasPathSum(root->right, targetSum-root->val);}
    if (!root->left && !root->right) {ret = targetSum==root->val;}

    return ret;
}

int main() {

    return 0;
}