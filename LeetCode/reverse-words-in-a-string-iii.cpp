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
    for (int i = 0, j = 1; j < s.length(); j++) {
        printf("(%d, %d)\n", i, j);
        if (s[j] == ' ') {
            for (int a = 0; a < (i+j)/2-i; a++) swap(s[i+a], s[j-a-1]);
            i = j+1;
        } else if (j == s.length()-1) {
            j++;
            for (int a = 0; a < (i+j)/2-i; a++) swap(s[i+a], s[j-a-1]);
        }
    }

    return s;
}

int main() {
    cout << reverseWords("abc cba");

    return 0;
}