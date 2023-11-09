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

const int M = 1e9+7;

int countHomogenous(string s) {
    char tmp = s[0]; long long cnt = 1, ret = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != tmp) {
            ret = (ret+(cnt*(cnt+1)/2))%M;
            tmp = s[i]; cnt = 1;
        } else cnt++;
    }
    ret = (ret+(cnt*(cnt+1)/2))%M;

    return ret;
}

int main() {
    cout << countHomogenous("abbcccaa");

    return 0;
}