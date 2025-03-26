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

bool chkVowel(char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {return true;}
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {return true;}
    return false;
}

bool halvesAreAlike(string s) {
    int n = s.length(), cntA = 0, cntB = 0;
    for (int i = 0; i < n/2; i++) {
        cntA += chkVowel(s[i]);
        cntB += chkVowel(s[i+n/2]);
    }

    return cntA == cntB;
}

int main() {
    cout << halvesAreAlike("book") << endl;
    cout << halvesAreAlike("textbook");

    return 0;
}