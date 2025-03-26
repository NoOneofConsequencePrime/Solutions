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
    int l = 0, r = 0;
    while (r < s.length()) {
        while (r < s.length() && s[r] != ' ') r++;
        reverse(s.begin()+l, s.begin()+r);
        l = r+1;
        r = l;
    }

    return s;
}

int main() {
    cout << reverseWords("abc cba");

    return 0;
}