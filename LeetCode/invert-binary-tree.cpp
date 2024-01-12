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
    swap(root->left, root->right);
    invertTree(root->left); invertTree(root->right);

    return root;
}

int main() {

    return 0;
}