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
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cntV(26, 0), len;
        for (auto &str : words) {
            len.push_back(str.length());
            for (char c : str) {cntV[c-'a']++;}
        }
        sort(len.begin(), len.end());
        int cntO = 0, cntE = 0;
        for (int x : cntV) {
            cntE += x;
            if (x%2 == 1) {
                cntO++;
                cntE--;
            }
        }
        
        int ret = 0;
        for (int x : len) {
            if (x%2 == 1) {
                if (cntE-x+1 >= 0 && cntO >= 1) {
                    ret++;
                    cntE -= x-1;
                    cntO--;
                } else if (cntE-x >= 0) {
                    ret++;
                    cntE -= x;
                }
            } else {
                if (cntE-x >= 0) {
                    cntE -= x;
                    ret++;
                }
            }
        }
        
        return ret;
    }
};

int main() {

    return 0;
}