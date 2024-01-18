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

int getDepth(TreeNode* cur) {
    if (!cur) {return -1;}

    return max(getDepth(cur->left), getDepth(cur->right))+1;
}

bool isBalanced(TreeNode* root) {
    if (!root) {return true;}
    if (abs(getDepth(root->left)-getDepth(root->right)) > 1) {return false;}

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {

    return 0;
}