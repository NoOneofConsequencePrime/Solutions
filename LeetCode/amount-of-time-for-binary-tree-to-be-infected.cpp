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

int amountOfTime(TreeNode* root, int start) {
    int hi = 0, lo = 0, startVal = 0, mid = 0;
    bool flag = false;
    while ((root->left != NULL) != (root->right != NULL)) {
        if (root->val == start) {startVal = mid; flag = true;}
        if (root->left) {root = root->left;}
        else {root = root->right;}
        mid++;
    }
    startVal = mid-startVal;
    queue<pair<TreeNode*, int>> q; q.push({root, 0});
    while (!q.empty()) {
        pair<TreeNode*, int> u = q.front(); q.pop();
        lo = min(lo, u.second); hi = max(hi, u.second);

        if (u.first->val == start) {
            startVal = u.second;
        }
        if (u.second < 0) {
            if (u.first->left) {q.push({u.first->left, u.second-1});}
            if (u.first->right) {q.push({u.first->right, u.second-1});}
        } else if (u.second > 0) {
            if (u.first->left) {q.push({u.first->left, u.second+1});}
            if (u.first->right) {q.push({u.first->right, u.second+1});}
        }
        if (u.second == 0) {
            if (u.first->left) {q.push({u.first->left, -1});}
            if (u.first->right) {q.push({u.first->right, 1});}
        }
    }

    printf("%d %d %d %d %d\n", lo, hi, mid, startVal, flag);

    int ret = 0;
    if (mid == 0) {ret = max(hi-startVal, startVal-lo);}
    else {
        if (flag) {ret = max(startVal+max(-lo, hi), max(mid-startVal, startVal));}
        else {ret = max(mid+abs(startVal), max(hi-startVal, startVal-lo));}
    }
    // if (lo != hi) {ret = max(ret, mid+abs(startVal));}

    return ret;
}

int main() {

    return 0;
}