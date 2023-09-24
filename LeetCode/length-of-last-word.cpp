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
    int a = 0, b = -1;
    for (int i = s.length()-1; i >= 0; i--) {
        if (b == -1 && s[i] != ' ') b = i;
        if (b != -1 && s[i] == ' ') {
            a = i+1; break;
        }
    }
    printf("%d %d", a, b);

    return b-a+1;
}

int main() {
    string s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s);

    return 0;
}