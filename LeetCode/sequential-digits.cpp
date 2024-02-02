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
        vector<int> ret;
        for (int i = 1; i <= 9; i++) {
            ll tmp = i;
            while (tmp <= high) {
                if (tmp >= low) {ret.push_back((int)tmp);}
                if (tmp%10 != 9) {tmp = tmp*10+tmp%10+1;}
                else {break;}
            }
        }
        sort(ret.begin(), ret.end());

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = ans.sequentialDigits(1000, 13000);
    for (int x : v) {cout << x << " ";}

    return 0;
}