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

string smallestSubsequence(string s) {
    int lApp[30];
    for (int i = 0; i < s.length(); i++) lApp[s[i]-'a'] = i;

    stack<char> st;
    bool chk[30]; memset(chk, false, sizeof(chk));
    for (int i = 0; i < s.length(); i++) {
        if (chk[s[i]-'a']) continue;
        while (!st.empty() && st.top() > s[i] && i < lApp[st.top()-'a']) {
            chk[st.top()-'a'] = false; st.pop();
        }
        st.push(s[i]); chk[s[i]-'a'] = true;
    }

    string ret = "";
    while (!st.empty()) {
        ret += st.top();
        st.pop();
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    cout << smallestSubsequence("cbacdcbc");

    return 0;
}