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

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        string str = "123456789";
        vector<int> ret;
        for (int len = 1; len <= 9; len++) {
            for (int i = 0; i < 9-len+1; i++) {
                int tmp = stoi(str.substr(i, len));
                if (low <= tmp && tmp <= high) {ret.push_back(tmp);}
            }
        }

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = ans.sequentialDigits(1000, 13000);
    for (int x : v) {cout << x << " ";}

    return 0;
}