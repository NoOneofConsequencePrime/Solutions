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
    string ret = "", tmp = "";
    for (char& c : s) {
        if (c != ' ') tmp += c;
        else {
            reverse(tmp.begin(), tmp.end());
            ret += tmp+" ";
            tmp = "";
        }
    }
    reverse(tmp.begin(), tmp.end());
    ret += tmp+" ";

    return ret.substr(0, ret.length()-1);
}

int main() {
    cout << reverseWords("Let's take LeetCode contest");

    return 0;
}