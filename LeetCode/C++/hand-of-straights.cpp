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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int m = hand.size();
    if (m%groupSize != 0) {return false;}
    sort(hand.begin(), hand.end());
    vector<pii> ord; ord.push_back({hand[0], 1});
    for (int i = 1; i < hand.size(); i++) {
        if (hand[i] != hand[i-1]) {ord.push_back({hand[i], 1});}
        else {ord[ord.size()-1].s++;}
    }

    int n = ord.size(), fi = 0;
    for (int i = 0; i < m/groupSize; i++) {
        while (fi < n && ord[fi].s == 0) {fi++;}
        if (fi >= n) {return false;}
        ord[fi].s--;
        for (int j = 1; j < groupSize; j++) {
            if (fi+j >= n) {return false;}
            if (ord[fi+j].f-ord[fi].f != j) {return false;}
            if (ord[fi+j].s == 0) {return false;}
            ord[fi+j].s--;
        }
    }

    return true;
}

int main() {
    vector<int> v = {2,1};
    cout << isNStraightHand(v, 2);

    return 0;
}