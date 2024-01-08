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

int rangeSumBST(TreeNode* root, int low, int high) {
    int ret = 0;
    if (root->val >= low && root->val <= high) ret = root->val;
    if (root->left != NULL) ret += rangeSumBST(root->left, low, high);
    if (root->right != NULL) ret += rangeSumBST(root->right, low, high);

    return ret;
}

int main() {

    return 0;
}