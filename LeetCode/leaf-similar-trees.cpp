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

void getLeafSeq(TreeNode* root, vector<int>& v) {
    if (root->left == NULL && root->right == NULL) {
        v.push_back(root->val);
        return;
    }
    if (root->left != NULL) getLeafSeq(root->left, v);
    if (root->right != NULL) getLeafSeq(root->right, v);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> a, b;
    getLeafSeq(root1, a); getLeafSeq(root2, b);
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

int main() {

    return 0;
}