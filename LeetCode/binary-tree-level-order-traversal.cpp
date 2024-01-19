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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) {return ret;}

    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        vector<int> tmpV;
        int n = q.size();
        while (n > 0) {
            TreeNode* cur = q.front(); q.pop();
            tmpV.push_back(cur->val);
            if (cur->left) {q.push(cur->left);}
            if (cur->right) {q.push(cur->right);}
            n--;
        }
        ret.push_back(tmpV);
    }

    return ret;
}

int main() {

    return 0;
}