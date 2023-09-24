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

int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != ' ') len++;
        else if (len > 0) break;
    }

    return len;
}

int main() {
    string s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s);

    return 0;
}