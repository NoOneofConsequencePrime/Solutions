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

int maxDepth(TreeNode* root) {
    if (!root) {return 0;}
    
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}

int main() {

    return 0;
}