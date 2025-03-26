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

string reverseWords(string s) {
    vector<string> v;
    string tmp = "";
    for (char& c : s) {
        if (c == ' ') {
            if (tmp.length() != 0) v.push_back(tmp);
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() != 0) v.push_back(tmp);

    string ret = "";
    for (int i = v.size()-1; i >= 0; i--) {
        ret += v[i];
        if (i != 0) ret += " ";
    }

    return ret;
}

int main() {
    cout << reverseWords("  hello world  ");

    return 0;
}