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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode *node) {
        int l = 0, r = 0;
        TreeNode *tmpNode = node;
        while (tmpNode) {
            l++;
            tmpNode = tmpNode->left;
        }
        tmpNode = node;
        while (tmpNode) {
            r++;
            tmpNode = tmpNode->right;
        }

        if (l == r) {return pow(2, r)-1;}
        return 1+height(node->left)+height(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        return height(root);
    }
};

int main() {

    return 0;
}