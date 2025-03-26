#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> ret;
    int len = digits.size(), cry = 0;
    if (digits[len-1] == 9) {
        ret.push_back(0); cry = 1;
    } else ret.push_back(digits[len-1]+1);
    for (int i = digits.size()-2; i >= 0; i--) {
        if (cry == 0) ret.push_back(digits[i]);
        else {
            if (digits[i] == 9) ret.push_back(0);
            else {
                ret.push_back(digits[i]+1); cry = 0;
            }
        }
    }
    if (cry) ret.push_back(1);
    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    vector<int> v = {8, 9};
    vector<int> ans = plusOne(v);
    for (auto& x : ans) cout << x << " ";

    return 0;
}