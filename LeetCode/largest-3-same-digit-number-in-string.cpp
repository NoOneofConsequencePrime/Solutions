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

string largestGoodInteger(string num) {
    char tmp = 'a', mx = '0'-1; int len = 0;
    for (char c : num) {
        if (c != tmp) {
            len = 1;
            tmp = c;
        } else {
            len++;
            if (len == 3 && mx < c) mx = c;
        }
    }

    if (mx == '0'-1) return "";
    else {
        string ret = ""; ret+=mx; ret+=mx; ret+=mx;
        return ret;
    }
}

int main() {
    cout << largestGoodInteger("6777133339");

    return 0;
}