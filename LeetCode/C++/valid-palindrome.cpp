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

bool chk(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
    return false;
}

bool isPalindrome(string s) {
    for (int i = 0, j = s.length()-1; i < j; i++, j--) {
        while (i < j && !chk(s[i])) i++;
        while (i < j && !chk(s[j])) j--;
        if (tolower(s[i]) != tolower(s[j])) return false;
        }
    }

    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}