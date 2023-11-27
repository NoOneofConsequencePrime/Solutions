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

string removeStars(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '*') stk.pop();
        else stk.push(c);
    }
    
    string ret(stk.size(), ' ');
    for (int i = ret.length()-1; i >= 0; i--) {
        ret[i] = stk.top();
        stk.pop();
    }

    return ret;
}

int main() {
    cout << removeStars("leet**cod*e");

    return 0;
}