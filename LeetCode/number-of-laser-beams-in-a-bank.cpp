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

int numberOfBeams(vector<string>& bank) {
    int ret = 0, pre = 0;
    for (int i = 0; i < bank.size(); i++) {
        int cnt = 0;
        for (char c : bank[i]) if (c == '1') cnt++;
        if (cnt != 0) {
            ret += cnt*pre;
            pre = cnt;
        }
    }

    return ret;
}

int main() {
    vector<string> v = {"011001","000000","010100","001000"};
    cout << numberOfBeams(v);

    return 0;
}