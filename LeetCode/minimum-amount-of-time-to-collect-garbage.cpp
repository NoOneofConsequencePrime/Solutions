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

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int ret = garbage[0].length(), m, p, g; m = p = g = 0;
    for (int i = 0; i < travel.size(); i++) {
        ret += garbage[i+1].length();
        m += travel[i]; p += travel[i]; g += travel[i];
        bool a, b, c; a = b = c = false;
        for (char chr : garbage[i+1]) {
            switch (chr) {
                case 'M':
                    a = true;
                    break;
                case 'P':
                    b = true;
                    break;
                case 'G':
                    c = true;
                    break;
            }
        }
        if (a) {
            ret += m; m = 0;
        }
        if (b) {
            ret += p; p = 0;
        }
        if (c) {
            ret += g; g = 0;
        }
    }

    return ret;
}

int main() {
    vector<string> a = {"G","P","GP","GG"}; vector<int> b = {2,4,3};
    cout << garbageCollection(a, b);

    return 0;
}