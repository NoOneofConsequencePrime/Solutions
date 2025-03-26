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

int mHash(pair<int, int> p) {
    return p.first*10000+p.second;
}

bool isPathCrossing(string path) {
    unordered_set<int> st;
    pair<int, int> cur = {0, 0}; st.insert(mHash(cur));
    for (char c : path) {
        switch(c) {
            case 'N':
                cur.first++;
                break;
            case 'S':
                cur.first--;
                break;
            case 'E':
                cur.second++;
                break;
            case 'W':
                cur.second--;
                break;
        }
        if (st.count(mHash(cur)) == 0) st.insert(mHash(cur));
        else return true;
    }

    return false;
}

int main() {
    cout << isPathCrossing("NESWW");

    return 0;
}