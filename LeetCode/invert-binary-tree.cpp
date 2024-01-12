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

void invertNode(TreeNode* node) {
    if (!node) {return;}
    swap(node->left, node->right);
    invertNode(node->left); invertNode(node->right);

    return;
}

TreeNode* invertTree(TreeNode* root) {
    invertNode(root);

    return root;
}

int main() {

    return 0;
}