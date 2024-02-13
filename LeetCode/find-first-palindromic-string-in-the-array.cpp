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
private:
    bool chkPal(string &str) {
        int n = str.length();
        for (int i = 0; i < n/2; i++) {
            if (str[i] != str[n-i-1]) {return false;}
        }

        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        for (auto &str : words) {
            if (chkPal(str)) {return str;}
        }

        return "";
    }
};

int main() {

    return 0;
}